#include "common/network/server_socket.hpp"
#include "client.hpp"

static constexpr size_t DEFAULT_MAX_CONCURRENT_CLIENTS = 10;

class ClientAccepter final
{
public:
    explicit ClientAccepter(std::unique_ptr<ServerSocket> server_socket);

    std::shared_ptr<Client> accept();

private:
    std::unique_ptr<ServerSocket> _server_socket;
};
