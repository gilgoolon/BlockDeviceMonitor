#pragma once
#include <string>

#include "common/unix.hpp"

static constexpr std::string_view DEFAULT_ATTRIBUTE_VALUE = "unknown";

class BlockDevice final
{
public:
    explicit BlockDevice(std::string device_name);

    std::string retrieve_model() const;

    std::string retrieve_vendor() const;

    size_t retrieve_size() const;

    size_t retrieve_partitions_count() const;

    bool retrieve_is_external() const;

private:
    const std::string _device_name;

    std::filesystem::path get_path() const;
};
