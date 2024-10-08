#include <string>

constexpr std::string_view CLASS_BLOCK_DEVICE_INFO_PATH = "/sys/class/block";
constexpr std::string_view BLOCK_DEVICE_MODEL_REL_PATH = "device/model";
constexpr std::string_view BLOCK_DEVICE_VENDOR_REL_PATH = "device/vendor";
constexpr std::string_view BLOCK_DEVICE_INFO_PATH = "/sys/block";
constexpr std::string_view BLOCK_DEVICE_REMOVABLE_REL_PATH = "removable";
constexpr std::string_view BLOCK_DEVICE_SIZE_REL_PATH = "size";
constexpr std::string_view DEV_SYSTEM_PATH = "/dev";
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
