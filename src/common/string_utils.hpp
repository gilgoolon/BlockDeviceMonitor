#pragma once
#include <string>
#include <vector>

namespace Strings
{
    constexpr size_t SPLIT_ONCE = 1;

    std::vector<std::string> split(const std::string &string, char token, size_t max);

    std::string strip(const std::string &str, char token);

    std::string to_string(char c);

    bool starts_with(const std::string &str, const std::string &prefix);
};