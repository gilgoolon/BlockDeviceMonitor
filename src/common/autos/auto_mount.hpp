#pragma once
#include <filesystem>
using namespace std::filesystem;

namespace Autos {
static constexpr uint32_t MOUNT_CREATE_NEW = 0;
static constexpr nullptr_t FILESYSTEM_FLAGS_NO_FLAGS = nullptr;

class AutoMount final {
public:
    explicit AutoMount(const std::filesystem::path& source, const std::filesystem::path& destination);

    ~AutoMount();

    AutoMount(const AutoMount&) = delete;

    AutoMount(AutoMount&&) = delete;

    AutoMount& operator=(const AutoMount&) = delete;

    AutoMount& operator=(AutoMount&&) = delete;

    static std::string detect_filesystem_type(const std::filesystem::path& device_name);

private:
    std::filesystem::path _source;
    std::filesystem::path _destination;
};
};
