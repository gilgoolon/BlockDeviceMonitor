#pragma once
#include <stdlib.h>
#include <string>
#include <filesystem>
using namespace std::filesystem;

namespace os
{
    constexpr char *MOUNT_ERROR_VALUE = nullptr;

    class TempFolder final
    {
    public:
        explicit TempFolder(const std::string &template_name);

        ~TempFolder();

        TempFolder(const TempFolder &) = delete;

        TempFolder(TempFolder &&) = delete;

        TempFolder &operator=(const TempFolder &) = delete;

        TempFolder &operator=(TempFolder &&) = delete;

        std::filesystem::path get() const;

    private:
        std::filesystem::path _path;
    };
}
