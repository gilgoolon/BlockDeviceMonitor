#include "client.hpp"

Client::Client(std::shared_ptr<IWriter> client_writer, std::shared_ptr<IReader> client_reader)
    : _client_writer(std::move(client_writer)), _client_reader(std::move(client_reader))
{
}

void Client::send(const ServerMessage &message)
{
    const auto serialized = message.SerializeAsString();
    _client_writer->write(Buffer::to_buffer(serialized));
}

ClientMessage Client::receive()
{
    const auto data = _client_reader->read();
    ClientMessage message;
    message.ParseFromString(Buffer::to_string(data));
    return message;
}