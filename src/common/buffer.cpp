#include "buffer.hpp"
using buffer::Buffer;

std::string buffer::to_string(const Buffer &buffer)
{
    return std::string(reinterpret_cast<const char *>(buffer.data()), buffer.size());
}

Buffer buffer::to_buffer(const std::string &str)
{
    return Buffer(str.begin(), str.end());
}
