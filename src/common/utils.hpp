#pragma once
#include <filesystem>
using namespace std::filesystem;

#include <vector>
#include <string>
#include "../exceptions.hpp"

namespace strings
{
    std::vector<std::string> split(const std::string &string, char token, size_t max);

    std::string strip(const std::string &str, char token);

    std::string to_string(char c);

    bool starts_with(const std::string &str, const std::string &prefix);
};

namespace os
{
    template <typename Func, typename... Args>
    int covered_call(const int error_value, Func func, Args... args)
    {
        int result = func(std::forward<Args>(args)...);
        if (error_value == result)
        {
            throw ErrnoException();
        }
        return result;
    }

    std::string read_text_file(const std::filesystem::path& path);
};
