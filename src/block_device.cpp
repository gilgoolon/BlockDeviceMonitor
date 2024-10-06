#include <sys/ioctl.h>
#include <linux/fs.h>
#include <fcntl.h>
#include <filesystem>
using namespace std::filesystem;

#include "block_device.hpp"
#include "common/utils.hpp"
#include "common/auto_fd.hpp"

BlockDevice::BlockDevice(std::string device_name) : _device_name(std::move(device_name)) {}

std::string BlockDevice::get_model() const
{
    try
    {
        const auto model_path = std::filesystem::path(CLASS_BLOCK_DEVICE_INFO_PATH) / _device_name / BLOCK_DEVICE_MODEL_REL_PATH;
        return strings::strip(os::read_text_file(model_path), '\n');
    }
    catch (...)
    {
        return std::string(DEFAULT_ATTRIBUTE_VALUE);
    }
}

std::string BlockDevice::get_vendor() const
{
    try
    {
        const auto vendor_path = std::filesystem::path(CLASS_BLOCK_DEVICE_INFO_PATH) / _device_name / BLOCK_DEVICE_VENDOR_REL_PATH;
        return strings::strip(os::read_text_file(vendor_path), '\n');
    }
    catch (...)
    {
        return std::string(DEFAULT_ATTRIBUTE_VALUE);
    }
}

size_t BlockDevice::get_size() const
{
    const auto vendor_path = std::filesystem::path(BLOCK_DEVICE_INFO_PATH) / _device_name / BLOCK_DEVICE_SIZE_REL_PATH;
    return std::stol(os::read_text_file(vendor_path));
}

size_t BlockDevice::get_partitions_count() const
{
    // TODO: Unimplemented
    return 0;
}

bool BlockDevice::is_external() const
{
    const auto removable_path = std::filesystem::path(BLOCK_DEVICE_INFO_PATH) / _device_name / BLOCK_DEVICE_REMOVABLE_REL_PATH;
    return std::stoi(os::read_text_file(removable_path));
}

std::filesystem::path BlockDevice::get_path() const
{
    return std::filesystem::path(DEV_SYSTEM_PATH) / _device_name;
}
