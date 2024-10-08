#include "buffer.hpp"

std::string to_string(const Buffer &buffer)
{
    return std::string(reinterpret_cast<const char *>(buffer.data()), buffer.size());
}

Buffer to_buffer(const std::string &str)
{
    return Buffer(str.begin(), str.end());
}
