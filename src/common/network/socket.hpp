#pragma once
#include "../autos/auto_fd.hpp"
#include "../buffer.hpp"
using Buffer::VBuffer;

class Socket final {
public:
    explicit Socket(const int socket_fd);

    void send(const VBuffer& data) const;

    VBuffer receive() const;

    uint32_t get_socket_fd() const;

    void shutdown() const;

private:
    const Autos::AutoFd _socket_fd;
};

std::shared_ptr<Socket> accept_client(const uint32_t port);
