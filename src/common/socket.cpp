#include <sys/socket.h>
#include <unistd.h>

#include "socket.hpp"
#include "utils.hpp"
#include "../exceptions.hpp"

Socket::Socket(const int socket_fd)
    : _socket_fd(make_auto_fd(socket_fd))
{
}

void Socket::send(const Buffer &data) const
{
    os::covered_call(UNIX_INT_ERROR_VALUE, ::send, *_socket_fd.get(), data.data(), data.size(), DEFAULT_NO_FLAGS);
}

Buffer Socket::receive() const
{
    Buffer buff;
    const size_t buff_size = DEFAULT_BUFF_SIZE;
    ssize_t bytes_read;
    do
    {
        const size_t old_size = buff.size();
        buff.resize(old_size + buff_size);
        bytes_read = os::covered_call(UNIX_INT_ERROR_VALUE, ::recv, *_socket_fd.get(), buff.data() + old_size, buff_size, DEFAULT_NO_FLAGS);
        if (!bytes_read)
        {
            throw DisconnectedException();
        }
        buff.resize(old_size + bytes_read);
    } while (bytes_read >= buff_size);
    return buff;
}

uint32_t Socket::get_socket_fd() const
{
    return *_socket_fd.get();
}
