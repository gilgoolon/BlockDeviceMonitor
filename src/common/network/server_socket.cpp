#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

#include "../os_utils.hpp"
#include "../unix.hpp"
#include "server_socket.hpp"

ServerSocket::ServerSocket(const uint32_t port)
    : _socket_fd(
          OS::covered_call(::socket, AF_INET,
              SOCK_STREAM, Flags::DEFAULT_NO_FLAGS))
{
    bind(port);
}

void ServerSocket::listen(const size_t max_connections) const
{
    OS::covered_call(::listen, *_socket_fd,
        max_connections);
}

std::shared_ptr<Socket> ServerSocket::accept() const
{
    return std::make_shared<Socket>(
        OS::covered_call(::accept, *_socket_fd,
            Flags::OPTIONAL_NO_OUTPUT, Flags::OPTIONAL_NO_OUTPUT));
}

void ServerSocket::shutdown() const
{
    OS::covered_call(::shutdown, *_socket_fd, SHUT_RDWR);
}

void ServerSocket::bind(const uint32_t port) const
{
    sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = ::htons(port);
    server_address.sin_addr.s_addr = INADDR_ANY;
    OS::covered_call(::bind, *_socket_fd,
        reinterpret_cast<const sockaddr*>(&server_address),
        sizeof(server_address));
}
