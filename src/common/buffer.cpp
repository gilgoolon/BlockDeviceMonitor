#include "buffer.hpp"
using Buffer::VBuffer;

std::string Buffer::to_string(const VBuffer& buffer)
{
    return std::string(reinterpret_cast<const char*>(buffer.data()), buffer.size());
}

VBuffer Buffer::to_buffer(const std::string& str)
{
    return VBuffer(str.begin(), str.end());
}
