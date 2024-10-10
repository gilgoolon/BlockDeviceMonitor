#include "client_accepter.hpp"
#include "writers/socket_writer.hpp"
#include "readers/socket_reader.hpp"

ClientAccepter::ClientAccepter(std::unique_ptr<ServerSocket> server_socket)
    : _server_socket(std::move(server_socket))
{
    _server_socket->listen(DEFAULT_MAX_CONCURRENT_CLIENTS);
}

std::shared_ptr<Client> ClientAccepter::accept()
{
    auto client_socket = _server_socket->accept();
    return std::make_shared<Client>(
        std::make_unique<SocketWriter>(client_socket),
        std::make_unique<SocketReader>(client_socket));
}
