#include "auto_temp_folder.hpp"
#include "../os_utils.hpp"

static const std::string TEMPDIR_TEMPALTE_SUFFIX = "XXXXXX";

Autos::AutoTempFolder::AutoTempFolder(const std::filesystem::path& template_path)
    : _path(template_path.string() + TEMPDIR_TEMPALTE_SUFFIX)
{
    static constexpr char* MKDTEMP_ERROR_VALUE = nullptr;

    if (MKDTEMP_ERROR_VALUE == mkdtemp(const_cast<char*>(_path.c_str()))) {
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
