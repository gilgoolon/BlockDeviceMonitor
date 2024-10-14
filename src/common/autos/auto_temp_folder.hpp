#pragma once
#include <stdlib.h>
#include <string>
#include <filesystem>
using namespace std::filesystem;

namespace autos
{
    constexpr char *MOUNT_ERROR_VALUE = nullptr;

    class AutoTempFolder final
    {
    public:
        explicit AutoTempFolder(const std::string &template_name);

        ~AutoTempFolder();

        AutoTempFolder(const AutoTempFolder &) = delete;

        AutoTempFolder(AutoTempFolder &&) = delete;

        AutoTempFolder &operator=(const AutoTempFolder &) = delete;

        AutoTempFolder &operator=(AutoTempFolder &&) = delete;

        std::filesystem::path get() const;

    private:
        std::filesystem::path _path;
    };
}
