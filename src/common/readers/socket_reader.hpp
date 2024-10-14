#pragma once
#include "../socket.hpp"
#include "reader.hpp"

class SocketReader final : public IReader
{
public:
    SocketReader(std::shared_ptr<Socket> socket);

    Buffer read() override;

private:
    std::shared_ptr<Socket> _socket;
};
