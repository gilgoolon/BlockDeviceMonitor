#include <iostream>

#include "block_device_monitor.hpp"
#include "exceptions.hpp"

enum ProgramArguments : int
{
    ProgramName,
    PortNumber,
    EndFinal
};

int main(const int argc, char **argv)
{
    if (ProgramArguments::EndFinal != argc)
    {
        std::cout << "Usage: " << argv[ProgramArguments::ProgramName] << " [port]" << std::endl;
        return EXIT_FAILURE;
    }
    int port;
    try
    {
        port = std::stoi(argv[ProgramArguments::PortNumber]);
    }
    catch (const std::invalid_argument &)
    {
        std::cout << "Please enter a valid port number." << std::endl;
        return EXIT_FAILURE;
    }
    try
    {
        auto monitor = make_block_device_monitor(port);
        monitor->start();
    }
    catch (const Exception &ex)
    {
        std::cout << "Failed to create/run monitor. Error: " << ex.what() << std::endl;
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}