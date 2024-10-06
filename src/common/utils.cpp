#include <sstream>
#include <fstream>

#include "utils.hpp"

std::vector<std::string> strings::split(std::string string, char delimiter)
{
    string += delimiter;
    std::stringstream ss(string);
    std::string segment;
    std::vector<std::string> seglist;

    while (std::getline(ss, segment, delimiter))
    {
        seglist.push_back(segment);
    }
    return seglist;
}

std::string strings::strip(std::string str, const char token)
{
    str.erase(std::remove(str.begin(), str.end(), token), str.cend());
    return str;
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
