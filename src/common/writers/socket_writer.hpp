#pragma once
#include "writer.hpp"
#include "../network/socket.hpp"

class SocketWriter final : public IWriter
{
public:
    explicit SocketWriter(std::shared_ptr<Socket> socket);

    void write(const buffer::Buffer &data) override;

private:
    std::shared_ptr<Socket> _socket;
};
