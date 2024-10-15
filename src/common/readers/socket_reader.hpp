#pragma once
#include "../network/socket.hpp"
#include "reader.hpp"
using Buffer::VBuffer;

class SocketReader final : public IReader
{
public:
    SocketReader(std::shared_ptr<Socket> socket);

    VBuffer read() override;

private:
    std::shared_ptr<Socket> _socket;
};
