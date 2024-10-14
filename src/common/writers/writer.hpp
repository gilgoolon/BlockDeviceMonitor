#pragma once
#include <string>

#include "../buffer.hpp"

class IWriter
{
public:
    virtual ~IWriter() = default;

    virtual void write(const Buffer &data) = 0;
};
