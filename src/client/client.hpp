#pragma once
#include <memory>

#include "../common/readers/reader.hpp"
#include "../common/writers/writer.hpp"
#include "../proto/client_message.pb.h"
#include "../proto/server_message.pb.h"

class Client final {
public:
    explicit Client(std::shared_ptr<IWriter> client_writer, std::shared_ptr<IReader> client_reader);

    void send(const ServerMessage& message);

    ClientMessage receive();

private:
    std::shared_ptr<IWriter> _client_writer;
    std::shared_ptr<IReader> _client_reader;
};
