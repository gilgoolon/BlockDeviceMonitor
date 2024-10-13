#include "client.hpp"

class ClientHandler final
{
public:
    explicit ClientHandler(std::shared_ptr<Client> client, std::shared_ptr<std::vector<Rule>> rules);

    void handle_indefinitely();

private:
    std::shared_ptr<Client> _client;
    std::shared_ptr<std::vector<Rule>> _rules;
};
