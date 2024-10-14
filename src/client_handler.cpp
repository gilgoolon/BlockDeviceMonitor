#include "proto/server_message.pb.h"

#include "client_handler.hpp"
#include "common/autos/auto_lock.hpp"

ClientHandler::ClientHandler(std::shared_ptr<Client> client, std::shared_ptr<RulesManager> rules_manager)
    : _client(std::move(client)), _rules_manager(std::move(rules_manager))
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
    _rules_manager->add_rule(add_rule_content.rule());
}

void ClientHandler::handle_remove_rule(ClientMessage &client_message)
{
    RemoveRuleClientMessageContent remove_rule_content;
    client_message.content().UnpackTo(&remove_rule_content);
    _rules_manager->remove_rule(remove_rule_content.rule_index());
}

void ClientHandler::handle_get_existing_rules(ClientMessage &client_message)
{
    ExistingRulesServerMessageContent content;
    {
        autos::AutoLock auto_rules_lock(_rules_manager->get_lock());
        for (auto &rule : *_rules_manager)
        {
            content.add_rules()->CopyFrom(rule);
        }
    }
    ServerMessage message;
    message.mutable_content()->PackFrom(content);
}
