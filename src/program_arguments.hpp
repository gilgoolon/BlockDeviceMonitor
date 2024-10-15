#include <filesystem>
#include <string>
#include <vector>
using namespace std::filesystem;



class ProgramArguments final {
public:
    explicit ProgramArguments(const int argc, char** argv);

    uint32_t get_port() const;

    std::filesystem::path get_results_path() const;

private:
    std::vector<std::string> _command_line;
};
