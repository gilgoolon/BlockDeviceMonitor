#include "socket_writer.hpp"
using Buffer::VBuffer;

SocketWriter::SocketWriter(std::shared_ptr<Socket> socket)
    : _socket(std::move(socket))
{
}

void SocketWriter::write(const VBuffer &data)
{
    _socket->send(data);
}