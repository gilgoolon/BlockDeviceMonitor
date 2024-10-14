#pragma once
#include <string>
using buffer::Buffer;

class IReader
{
public:
    virtual ~IReader() = default;

    virtual Buffer read() = 0;
};
