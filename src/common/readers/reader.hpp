#pragma once
#include <string>

#include "../buffer.hpp"
using Buffer::VBuffer;

class IReader {
public:
    virtual ~IReader() = default;

    virtual VBuffer read() = 0;
};
