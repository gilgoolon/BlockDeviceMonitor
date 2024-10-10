#include "client_handler.hpp"

ClientHandler::ClientHandler(std::shared_ptr<Client> client)
    : _client(client)
{
}

void ClientHandler::handle_indefinitely()
{
    std::cout << __FUNCTION__ << " handle client commands loop" << std::endl;
    sleep(1000);
}
