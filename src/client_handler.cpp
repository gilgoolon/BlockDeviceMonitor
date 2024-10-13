#include "proto/server_message.pb.h"

#include "client_handler.hpp"

ClientHandler::ClientHandler(std::shared_ptr<Client> client, std::shared_ptr<std::vector<Rule>> rules)
    : _client(client), _rules(std::move(rules))
{
}

void ClientHandler::handle_indefinitely()
{
    std::cout << __FUNCTION__ << " handle client commands loop" << std::endl;
    while (true)
    {
        auto client_message = _client->receive();
        switch (client_message.type())
        {
        case ADD_RULE:
            handle_add_rule(client_message);
            break;

        case REMOVE_RULE:
            handle_remove_rule(client_message);
            break;

        case GET_EXISTING_RULES:
            handle_get_existing_rules(client_message);
            break;

        default:
            break;
        }
    }
}

void ClientHandler::handle_add_rule(ClientMessage &client_message)
{
    AddRuleClientMessageContent add_rule_content;
    client_message.content().UnpackTo(&add_rule_content);
    _rules->push_back(add_rule_content.rule());
}

void ClientHandler::handle_remove_rule(ClientMessage &client_message)
{
    RemoveRuleClientMessageContent remove_rule_content;
    client_message.content().UnpackTo(&remove_rule_content);
    _rules->erase(_rules->begin() + remove_rule_content.rule_index());
}

void ClientHandler::handle_get_existing_rules(ClientMessage &client_message)
{
    ExistingRulesServerMessageContent content;
    for (auto &rule : *_rules)
    {
        content.add_rules()->CopyFrom(rule);
    }
    ServerMessage message;
    message.mutable_content()->PackFrom(content);
}
