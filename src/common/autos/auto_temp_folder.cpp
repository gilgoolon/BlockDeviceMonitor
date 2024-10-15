#include "auto_temp_folder.hpp"
#include "../os_utils.hpp"

Autos::AutoTempFolder::AutoTempFolder(const std::string& template_name)
    : _path(template_name)
{
    if (MOUNT_ERROR_VALUE == mkdtemp(const_cast<char*>(_path.c_str()))) {
        throw ErrnoException();
    }
}

Autos::AutoTempFolder::~AutoTempFolder()
{
    std::filesystem::remove_all(_path);
}

std::filesystem::path Autos::AutoTempFolder::get() const
{
    return _path;
}
