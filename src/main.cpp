#include <iostream>

#include "block_device_monitor.hpp"
#include "exceptions.hpp"

enum ProgramArguments : int {
    ProgramName,
    ResultsPath,
    Port,
    EndFinal
};

int main(const int argc, char** argv)
{
    if (ProgramArguments::EndFinal != argc) {
        std::cout << "Usage: " << argv[ProgramArguments::ProgramName] << " [results_path] [port]" << std::endl;
        return EXIT_FAILURE;
    }
    std::filesystem::path results_path = argv[ProgramArguments::ResultsPath];
    if (std::filesystem::is_directory(results_path)) {
        std::cout << "results_path: please enter a valid directory." << std::endl;
        return EXIT_FAILURE;
    }
    uint32_t port;
    try {
        port = std::stoi(argv[ProgramArguments::Port]);
    } catch (const std::invalid_argument&) {
        std::cout << "port: please enter a valid port number." << std::endl;
        return EXIT_FAILURE;
    }
    try {
        auto monitor = make_block_device_monitor(results_path, port);
        std::cout << "Monitoring device events..." << std::endl;
        monitor->start();
    } catch (const Exception& ex) {
        std::cout << "Failed to create/run monitor. Error: " << ex.what() << std::endl;
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}