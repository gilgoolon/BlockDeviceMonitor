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

void Socket::send(const Buffer &data) const
{
    os::covered_call(::send, *_socket_fd, data.data(), data.size(), flags::DEFAULT_NO_FLAGS);
}

Buffer Socket::receive() const
{
    Buffer buffer;
    const size_t buff_size = buffer::DEFAULT_BUFF_SIZE;
    ssize_t read_bytes = 0;
    do
    {
        const size_t old_size = buffer.size();
        buffer.resize(old_size + buff_size);
        read_bytes = os::covered_call(recv, *_socket_fd, buffer.data() + old_size, buff_size, flags::DEFAULT_NO_FLAGS);
        if (!read_bytes)
        {
            throw Exception(ExceptionCode::DisconnectedException, "client closed the connection");
        }
        buffer.resize(old_size + read_bytes);
    } while (read_bytes >= buffer::DEFAULT_BUFF_SIZE);
    return buffer;
}

uint32_t Socket::get_socket_fd() const
{
    return *_socket_fd;
}

void Socket::shutdown() const
{
    os::covered_call(::shutdown, *_socket_fd, SHUT_RDWR);
}

std::shared_ptr<Socket> accept_client(const uint32_t port)
{
    ServerSocket server_socket(port);
    server_socket.listen(1);
    return std::move(server_socket.accept());
}
