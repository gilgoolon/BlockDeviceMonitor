#pragma once
#include "client.hpp"
#include "../common/network/server_socket.hpp"

static constexpr size_t DEFAULT_MAX_BACKLOG = 10;

class ClientAccepter final
{
public:
    explicit ClientAccepter(std::unique_ptr<ServerSocket> server_socket, size_t max_backlog = DEFAULT_MAX_BACKLOG);

    std::shared_ptr<Client> accept();

private:
    std::unique_ptr<ServerSocket> _server_socket;
};
