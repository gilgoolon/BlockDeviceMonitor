#include "console_writer.hpp"
using Buffer::VBuffer;

void ConsoleWriter::write(const VBuffer &data)
{
    std::cout << Buffer::to_string(data) << std::endl;
}
