#include "socket_reader.hpp"

SocketReader::SocketReader(std::shared_ptr<Socket> socket)
    : _socket(std::move(socket))
{
}

Buffer SocketReader::read()
{
    return _socket->receive();
}
