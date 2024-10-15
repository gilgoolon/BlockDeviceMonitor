#include "program_arguments.hpp"
#include "exceptions.hpp"

enum class ProgramArgumentsSelector : size_t {
    ProgramName = 0,
    ResultsPath,
    Port,
    EndFinal
};

ProgramArguments::ProgramArguments(const int argc, char** argv)
{
    if (argc != static_cast<size_t>(ProgramArgumentsSelector::EndFinal)) {
        throw Exception(ExceptionCode::InvalidArgument, "Usage: " + std::string(argv[static_cast<size_t>(ProgramArgumentsSelector::ProgramName)]) + " [results_path] [port]");
    }
    for (size_t i = 0; i < argc; i++) {
        _command_line.push_back(argv[i]);
    }
}

uint32_t ProgramArguments::get_port() const
{
    try {
        return std::stoi(_command_line.at(static_cast<size_t>(ProgramArgumentsSelector::Port)));
    } catch (const std::exception& ex) {
        throw Exception(ExceptionCode::InvalidArgument, std::string("port: ") + ex.what());
    }
}

std::filesystem::path ProgramArguments::get_results_path() const
{
    std::filesystem::path path = _command_line.at(static_cast<size_t>(ProgramArgumentsSelector::ResultsPath));
    if (std::filesystem::is_directory(path)) {
        throw Exception(ExceptionCode::InvalidArgument, "results_path: please enter a valid directory");
    }
    return path;
}