#pragma once
#include "client.hpp"
#include "rules_manager.hpp"

class ClientHandler final {
public:
    explicit ClientHandler(std::shared_ptr<Client> client, std::shared_ptr<RulesManager> rules_manager);

    void handle_indefinitely();

private:
    std::shared_ptr<Client> _client;
    std::shared_ptr<RulesManager> _rules_manager;

    void handle_add_rule(ClientMessage& client_message);

    void handle_remove_rule(ClientMessage& client_message);

    void handle_get_existing_rules(ClientMessage& client_message);
};
