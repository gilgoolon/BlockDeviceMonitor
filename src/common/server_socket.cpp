#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

#include "../exceptions.hpp"
#include "server_socket.hpp"
#include "utils.hpp"

ServerSocket::ServerSocket(const int port) : _socket_fd(
                                                 make_auto_fd(os::covered_call(UNIX_INT_ERROR_VALUE, &::socket, AF_INET,
                                                                               SOCK_STREAM, DEFAULT_NO_FLAGS)))
{
    sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = ::htons(port);
    server_address.sin_addr.s_addr = INADDR_ANY;
    os::covered_call(UNIX_INT_ERROR_VALUE, ::bind, *_socket_fd.get(),
                     reinterpret_cast<const sockaddr *>(&server_address),
                     sizeof(server_address));
}

void ServerSocket::listen(const size_t max_connections) const
{
    os::covered_call(UNIX_INT_ERROR_VALUE, ::listen, *_socket_fd.get(),
                     max_connections);
}

std::unique_ptr<Socket> ServerSocket::accept() const
{
    return std::make_unique<Socket>(
        os::covered_call(UNIX_INT_ERROR_VALUE, ::accept, *_socket_fd.get(),
                         OPTIONAL_NO_OUTPUT, OPTIONAL_NO_OUTPUT));
}
