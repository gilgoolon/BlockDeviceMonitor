#include <filesystem>
using namespace std::filesystem;

#include <vector>
#include <string>
#include "../exceptions.hpp"

namespace strings
{
    std::vector<std::string> split(std::string string, char token);

    std::string strip(std::string str, char token);
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

    std::string read_text_file(std::filesystem::path path);
};
