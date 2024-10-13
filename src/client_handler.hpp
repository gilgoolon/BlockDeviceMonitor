#include "client.hpp"
#include "proto/rule.pb.h"

class ClientHandler final
{
public:
    explicit ClientHandler(std::shared_ptr<Client> client, std::shared_ptr<std::vector<Rule>> rules);

    void handle_indefinitely();

private:
    std::shared_ptr<Client> _client;
    std::shared_ptr<std::vector<Rule>> _rules;

    void handle_add_rule(ClientMessage &client_message);

    void handle_remove_rule(ClientMessage &client_message);

    void handle_get_existing_rules(ClientMessage &client_message);
};
