#include <sys/socket.h>
#include <unistd.h>
#include <poll.h>
#include <unistd.h>

#include "server_socket.hpp"
#include "socket.hpp"
#include "../os_utils.hpp"
#include "../unix.hpp"

Socket::Socket(const int socket_fd)
    : _socket_fd(socket_fd)
{
}

void Socket::send(const VBuffer &data) const
{
    OS::covered_call(::send, *_socket_fd, data.data(), data.size(), Flags::DEFAULT_NO_FLAGS);
}

VBuffer Socket::receive() const
{
    VBuffer buffer;
    const size_t buff_size = Buffer::DEFAULT_BUFF_SIZE;
    ssize_t read_bytes = 0;
    do
    {
        const size_t old_size = buffer.size();
        buffer.resize(old_size + buff_size);
        read_bytes = OS::covered_call(recv, *_socket_fd, buffer.data() + old_size, buff_size, Flags::DEFAULT_NO_FLAGS);
        if (!read_bytes)
        {
            throw Exception(ExceptionCode::DisconnectedException, "client closed the connection");
        }
        buffer.resize(old_size + read_bytes);
    } while (read_bytes >= Buffer::DEFAULT_BUFF_SIZE);
    return buffer;
}

uint32_t Socket::get_socket_fd() const
{
    return *_socket_fd;
}

void Socket::shutdown() const
{
    OS::covered_call(::shutdown, *_socket_fd, SHUT_RDWR);
}

std::shared_ptr<Socket> accept_client(const uint32_t port)
{
    ServerSocket server_socket(port);
    server_socket.listen(1);
    return std::move(server_socket.accept());
}
