#pragma once

#include <string>
#include <filesystem>
using namespace std::filesystem;

#include "../exceptions.hpp"

namespace os
{
    constexpr int UNIX_INT_ERROR_VALUE = -1;

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

    template <typename Func, typename... Args>
    int covered_call(Func func, Args... args)
    {
        return covered_call(UNIX_INT_ERROR_VALUE, func, args...);
    }

    template <typename Callable, typename ReturnType, typename... Args>
    ReturnType call_with_default(const ReturnType &default_value, Callable func, Args... args)
    {
        try
        {
            return func(args...);
        }
        catch (const Exception &e)
        {
            return default_value;
        }
    }

    std::string read_text_file(const std::filesystem::path &path);

    std::string current_unix_timestamp_str();

    void makedirs(const std::filesystem::path &path);
};