#pragma once
#include <memory>
#include <netinet/in.h>

#include "../autos/auto_fd.hpp"
#include "socket.hpp"

class ServerSocket final {
public:
    explicit ServerSocket(uint32_t port);

    void listen(size_t max_connections) const;

    std::shared_ptr<Socket> accept() const;

    void shutdown() const;

private:
    const Autos::AutoFd _socket_fd;

    void bind(uint32_t port) const;
};
