#include "client_accepter.hpp"
#include "../common/readers/socket_reader.hpp"
#include "../common/writers/socket_writer.hpp"

ClientAccepter::ClientAccepter(std::unique_ptr<ServerSocket> server_socket, const size_t max_backlog)
    : _server_socket(std::move(server_socket))
{
    _server_socket->listen(max_backlog);
}

std::shared_ptr<Client> ClientAccepter::accept()
{
    auto client_socket = _server_socket->accept();
    return std::make_shared<Client>(
        std::make_unique<SocketWriter>(client_socket),
        std::make_unique<SocketReader>(client_socket));
}
