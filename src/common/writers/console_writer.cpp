#include "console_writer.hpp"

void ConsoleWriter::write(const Buffer &data)
{
    std::cout << to_string(data) << std::endl;
}
