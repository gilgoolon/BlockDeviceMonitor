#pragma once
#include <cstdint>
#include <string>
#include <vector>

namespace Buffer {
using Byte = uint8_t;
using VBuffer = std::vector<Byte>;

constexpr size_t DEFAULT_BUFF_SIZE = 4096;

std::string to_string(const VBuffer& buffer);

VBuffer to_buffer(const std::string& str);

}; // namespace Buffer
