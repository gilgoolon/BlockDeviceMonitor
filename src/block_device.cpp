#include <sys/ioctl.h>
#include <linux/fs.h>
#include <fcntl.h>
#include <algorithm>

#include "block_device.hpp"
#include "common/utils.hpp"
#include "common/auto_fd.hpp"
#include "partition_table.hpp"
#include "common/unix.hpp"
#include <iostream>

BlockDevice::BlockDevice(std::string device_name) : _device_name(std::move(device_name)) {}

std::string BlockDevice::get_name() const
{
    return _device_name;
}

std::string BlockDevice::retrieve_model() const
{
    try
    {
        const auto model_path = paths::CLASS_BLOCK_DEVICE_INFO_PATH / _device_name / paths::BLOCK_DEVICE_MODEL_REL_PATH;
        return strings::strip(os::read_text_file(model_path), '\n');
    }
    catch (const Exception &ex)
    {
        if (ex.code() == ExceptionCode::InvalidFile)
        {
            throw Exception(ExceptionCode::MissingInformation, "model file doesn't exist for device " + _device_name);
        }
        else
        {
            throw ex;
        }
    }
}

std::string BlockDevice::retrieve_vendor() const
{
    try
    {
        const auto vendor_path = paths::CLASS_BLOCK_DEVICE_INFO_PATH / _device_name / paths::BLOCK_DEVICE_VENDOR_REL_PATH;
        return strings::strip(os::read_text_file(vendor_path), '\n');
    }
    catch (const Exception &ex)
    {
        if (ex.code() == ExceptionCode::InvalidFile)
        {
            throw Exception(ExceptionCode::MissingInformation, "vendor file doesn't exist for device " + _device_name);
        }
        else
        {
            throw ex;
        }
    }
}

size_t BlockDevice::retrieve_size() const
{
    try
    {
        const auto vendor_path = paths::BLOCK_DEVICE_INFO_PATH / _device_name / paths::BLOCK_DEVICE_SIZE_REL_PATH;
        return std::stol(os::read_text_file(vendor_path));
    }
    catch (const Exception &ex)
    {
        if (ex.code() == ExceptionCode::InvalidFile)
        {
            throw Exception(ExceptionCode::MissingInformation, "size file doesn't exist for device " + _device_name);
        }
        else
        {
            throw ex;
        }
    }
    catch (const std::invalid_argument &ex)
    {
        throw Exception(ExceptionCode::MissingInformation, "size file contents were not a valid size for device " + _device_name);
    }
}

size_t BlockDevice::retrieve_partitions_count() const
{
    const auto partition_table = get_partition_table();
    const auto device_entry_result = std::find_if(partition_table.begin(), partition_table.end(), [this](const auto &entry)
                                                  { return entry.name == _device_name; });
    if (device_entry_result == partition_table.end())
    {
        throw Exception(ExceptionCode::MissingInformation, "device is not in partitions table");
    }
    const auto device_entry = *device_entry_result;
    return std::count_if(partition_table.begin(), partition_table.end(), [device_entry](const auto &entry)
                         { return strings::starts_with(entry.name, device_entry.name) && entry.major == device_entry.major; });
}

bool BlockDevice::retrieve_is_external() const
{
    try
    {
        const auto removable_path = paths::BLOCK_DEVICE_INFO_PATH / _device_name / paths::BLOCK_DEVICE_REMOVABLE_REL_PATH;
        return std::stoi(os::read_text_file(removable_path));
    }
    catch (const Exception &ex)
    {
        if (ex.code() == ExceptionCode::InvalidFile)
        {
            throw Exception(ExceptionCode::MissingInformation, "external file doesn't exist for device " + _device_name);
        }
        else
        {
            throw ex;
        }
    }
}

std::filesystem::path BlockDevice::get_path() const
{
    return paths::DEV_SYSTEM_PATH / _device_name;
}
