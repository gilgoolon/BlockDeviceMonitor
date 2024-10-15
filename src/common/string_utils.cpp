#include <sstream>
#include <algorithm>

#include "string_utils.hpp"

std::vector<std::string> Strings::split(const std::string &string, char delimiter, const size_t max)
{
    std::stringstream ss(string + delimiter);
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

std::string Strings::strip(const std::string &str, const char token)
{
    std::string copy = str;
    copy.erase(std::remove(copy.begin(), copy.end(), token), copy.cend());
    return copy;
}

std::string Strings::to_string(char c)
{
    return std::string(1, c);
}

bool Strings::starts_with(const std::string &str, const std::string &prefix)
{
    return str.find(prefix) == 0;
}