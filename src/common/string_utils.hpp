#pragma once
#include <string>
#include <vector>

namespace Strings {
static const size_t SPLIT_ONCE = 1;

std::vector<std::string> split(const std::string& string, const char token, const size_t max);

std::string strip(const std::string& str, const char token);

std::string to_string(const char c);

bool starts_with(const std::string& str, const std::string& prefix);
}; // namespace Strings