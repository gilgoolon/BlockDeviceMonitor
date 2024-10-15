#pragma once
#include <filesystem>
#include <stdlib.h>
#include <string>
using namespace std::filesystem;

namespace Autos {
constexpr char* MOUNT_ERROR_VALUE = nullptr;

class AutoTempFolder final {
public:
    explicit AutoTempFolder(const std::string& template_name);

    ~AutoTempFolder();

    AutoTempFolder(const AutoTempFolder&) = delete;

    AutoTempFolder(AutoTempFolder&&) = delete;

    AutoTempFolder& operator=(const AutoTempFolder&) = delete;

    AutoTempFolder& operator=(AutoTempFolder&&) = delete;

    std::filesystem::path get() const;

private:
    std::filesystem::path _path;
};
}
