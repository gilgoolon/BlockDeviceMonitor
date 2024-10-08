#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

#include "../exceptions.hpp"
#include "server_socket.hpp"
#include "utils.hpp"

ServerSocket::ServerSocket(const uint32_t port) : _socket_fd(
                                                      os::covered_call(::socket, AF_INET,
                                                                       SOCK_STREAM, flags::DEFAULT_NO_FLAGS))
{
    bind(port);
}

void ServerSocket::listen(const size_t max_connections) const
{
    os::covered_call(::listen, *_socket_fd,
                     max_connections);
}

std::unique_ptr<Socket> ServerSocket::accept() const
{
    return std::make_unique<Socket>(
        os::covered_call(::accept, *_socket_fd,
                         flags::OPTIONAL_NO_OUTPUT, flags::OPTIONAL_NO_OUTPUT));
}

void ServerSocket::bind(const uint32_t port) const
{
    sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = ::htons(port);
    server_address.sin_addr.s_addr = INADDR_ANY;
    os::covered_call(::bind, *_socket_fd,
                     reinterpret_cast<const sockaddr *>(&server_address),
                     sizeof(server_address));
}
