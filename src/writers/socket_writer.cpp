#include "socket_writer.hpp"

SocketWriter::SocketWriter(std::shared_ptr<Socket> socket)
    : _socket(std::move(socket))
{
}

void SocketWriter::write(const Buffer &data)
{
    _socket->send(data);
}