#include <fstream>

#include "os_utils.hpp"

std::string os::read_text_file(const std::filesystem::path &path)
{
    std::ifstream file(path);
    if (!file)
    {
        throw Exception(ExceptionCode::InvalidFile, "Failed to open file");
    }

    std::ostringstream content;
    content << file.rdbuf();
    return content.str();
}

std::string os::current_unix_timestamp_str()
{
    return std::to_string(std::time(nullptr));
}

void os::makedirs(const std::filesystem::path &path)
{
    std::filesystem::path working_path = path;
    if (!std::filesystem::is_directory(working_path))
    {
        working_path = working_path.parent_path();
    }
    std::filesystem::create_directories(working_path);
}