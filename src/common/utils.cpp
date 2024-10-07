#include <sstream>
#include <fstream>

#include "utils.hpp"

std::vector<std::string> strings::split(std::string string, char delimiter, const size_t max)
{
    string += delimiter;
    std::stringstream ss(string);
    std::string segment;
    std::vector<std::string> seglist;

    for (size_t i = 0; i < max && std::getline(ss, segment, delimiter); i++)
    {
        seglist.push_back(segment);
    }

    std::getline(ss, segment, '\0');
    if (!segment.empty())
    {
        seglist.push_back(segment.substr(0, segment.length() - 1));
    }
    return seglist;
}

std::string strings::strip(std::string str, const char token)
{
    str.erase(std::remove(str.begin(), str.end(), token), str.cend());
    return str;
}

std::string strings::to_string(char c)
{
    return std::string(1, c);
}

std::string os::read_text_file(std::filesystem::path path)
{
    std::ifstream file(path);
    if (!file)
    {
        throw std::runtime_error("Failed to open file");
    }

    std::ostringstream content;
    content << file.rdbuf();
    return content.str();
}
