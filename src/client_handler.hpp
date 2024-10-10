#include "client.hpp"

class ClientHandler final
{
public:
    explicit ClientHandler(std::shared_ptr<Client> client);

    void handle_indefinitely();

private:
    std::shared_ptr<Client> _client;
};
