#pragma once
#include <vector>
#include <cstdint>
#include <string>

namespace buffer
{

    using Byte = uint8_t;
    using Buffer = std::vector<Byte>;

    constexpr size_t DEFAULT_BUFF_SIZE = 4096;

    std::string to_string(const Buffer &buffer);

    Buffer to_buffer(const std::string &str);

};
