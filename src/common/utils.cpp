#include "utils.hpp"
#include <sstream>

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