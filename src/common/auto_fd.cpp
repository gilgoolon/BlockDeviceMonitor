#include "auto_fd.hpp"
#include "os_utils.hpp"

AutoFd::AutoFd(const int fd)
    : _fd(fd)
{
}

AutoFd::AutoFd(const AutoFd &&fd)
{
    _fd = fd._fd;
}

AutoFd &AutoFd::operator=(const AutoFd &&fd)
{
    _fd = fd._fd;
    return *this;
}

AutoFd::~AutoFd()
{
    try
    {
        if (os::UNIX_INT_ERROR_VALUE != _fd)
        {
            os::covered_call(::close, _fd);
        }
    }
    catch (...)
    {
    }
}

int AutoFd::get() const
{
    return _fd;
}

int AutoFd::operator*() const
{
    return get();
}
