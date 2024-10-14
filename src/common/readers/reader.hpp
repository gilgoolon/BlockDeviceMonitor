#pragma once
#include <string>

class IReader
{
public:
    virtual ~IReader() = default;

    virtual Buffer read() = 0;
};
