#include <iostream>

#include "block_device_monitor.hpp"
#include "exceptions.hpp"
#include "program_arguments.hpp"

int main(const int argc, char** argv)
{
    std::filesystem::path results_path;
    uint32_t port;
    try {
        ProgramArguments args(argc, argv);
        results_path = args.get_results_path();
        port = args.get_port();
    } catch (const Exception& ex) {
        std::cerr << ex.what() << std::endl;
    }
    try {
        auto monitor = make_block_device_monitor(results_path, port);
        std::cout << "Monitoring device events..." << std::endl;
        monitor->start();
    } catch (const Exception& ex) {
        std::cerr << "Failed to create/run monitor. Error: " << ex.what() << std::endl;
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}