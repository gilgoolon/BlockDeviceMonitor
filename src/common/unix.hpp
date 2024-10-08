#pragma once
#include <cstddef>
#include <filesystem>
using namespace std::filesystem;

namespace flags
{
    constexpr int DEFAULT_NO_FLAGS = 0;
    constexpr nullptr_t OPTIONAL_NO_OUTPUT = nullptr;
};

namespace paths
{
    static const std::filesystem::path CLASS_BLOCK_DEVICE_INFO_PATH = "/sys/class/block";
    static const std::filesystem::path BLOCK_DEVICE_MODEL_REL_PATH = "device/model";
    static const std::filesystem::path BLOCK_DEVICE_VENDOR_REL_PATH = "device/vendor";
    static const std::filesystem::path BLOCK_DEVICE_INFO_PATH = "/sys/block";
    static const std::filesystem::path BLOCK_DEVICE_REMOVABLE_REL_PATH = "removable";
    static const std::filesystem::path BLOCK_DEVICE_SIZE_REL_PATH = "size";
    static const std::filesystem::path DEV_SYSTEM_PATH = "/dev";
};
