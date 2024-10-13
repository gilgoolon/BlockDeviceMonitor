#include <sys/mount.h>
#include <blkid/blkid.h>

#include "auto_mount.hpp"
#include "utils.hpp"

os::AutoMount::AutoMount(const std::filesystem::path &source, const std::filesystem::path &destination)
    : _source(source), _destination(destination)
{
    const auto filesystem_type = detect_filesystem_type(source);
    os::makedirs(_destination);
    os::covered_call(::mount, _source.c_str(), _destination.c_str(), filesystem_type.c_str(), MOUNT_CREATE_NEW, FILESYSTEM_FLAGS_NO_FLAGS);
}

os::AutoMount::~AutoMount()
{
    // umount2 instead of regular umount to force unmounting
    try
    {
        os::covered_call(::umount2, _destination.c_str(), MNT_FORCE);
    }
    catch (...)
    {
    }
}

std::string os::AutoMount::detect_filesystem_type(const std::filesystem::path &device_name)
{
    blkid_probe pr = blkid_new_probe_from_filename(device_name.c_str());
    if (!pr)
    {
        throw Exception(ExceptionCode::RuntimeError, "Failed to open device: " + device_name.string());
    }

    // Perform the probe on the device
    if (blkid_do_probe(pr))
    {
        blkid_free_probe(pr);
        throw Exception(ExceptionCode::RuntimeError, "Failed to probe device: " + device_name.string());
    }

    const char *filesystem_type;
    if (!blkid_probe_lookup_value(pr, "TYPE", &filesystem_type, nullptr))
    {
        blkid_free_probe(pr);
        return std::string(filesystem_type);
    }

    blkid_free_probe(pr);
    throw Exception(ExceptionCode::RuntimeError, "Failed to determine filesystem type for device: " + device_name.string());
}