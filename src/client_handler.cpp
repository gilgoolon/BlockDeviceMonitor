#include "client_handler.hpp"

ClientHandler::ClientHandler(std::shared_ptr<Client> client, std::shared_ptr<std::vector<Rule>> rules)
    : _client(client), _rules(std::move(rules))
{
}

void ClientHandler::handle_indefinitely()
{
    std::cout << __FUNCTION__ << " handle client commands loop" << std::endl;
    sleep(1000);
}
