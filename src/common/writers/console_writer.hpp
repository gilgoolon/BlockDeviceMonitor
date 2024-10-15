#pragma once
#include <iostream>

#include "writer.hpp"

class ConsoleWriter final : public IWriter {
public:
    explicit ConsoleWriter() = default;

    void write(const Buffer::VBuffer& data) override;
};
