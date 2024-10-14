#pragma once
#include "../buffer.hpp"
#include "../autos/auto_fd.hpp"

class Socket final
{
public:
    explicit Socket(int socket_fd);

    void send(const Buffer &data) const;

    Buffer receive() const;

    uint32_t get_socket_fd() const;

    void shutdown() const;

private:
    const AutoFd _socket_fd;
};

std::shared_ptr<Socket> accept_client(const uint32_t port);
