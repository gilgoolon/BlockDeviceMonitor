#include <filesystem>
using namespace std::filesystem;

#include "temp_folder.hpp"
#include "os_utils.hpp"

os::TempFolder::TempFolder(const std::string &template_name)
    : _path(template_name)
{
    if (MOUNT_ERROR_VALUE == mkdtemp(const_cast<char *>(_path.c_str())))
    {
        throw ErrnoException();
    }
}

os::TempFolder::~TempFolder()
{
    std::filesystem::remove_all(_path);
}

std::filesystem::path os::TempFolder::get() const
{
    return _path;
}
