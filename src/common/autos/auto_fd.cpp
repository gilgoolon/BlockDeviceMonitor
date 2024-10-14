#include "auto_fd.hpp"
#include "../os_utils.hpp"

autos::AutoFd::AutoFd(const int fd)
    : _fd(fd)
{
}

autos::AutoFd::AutoFd(const AutoFd &&fd)
{
    _fd = fd._fd;
}

autos::AutoFd &autos::AutoFd::operator=(const AutoFd &&fd)
{
    _fd = fd._fd;
    return *this;
}

autos::AutoFd::~AutoFd()
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

int autos::AutoFd::get() const
{
    return _fd;
}

int autos::AutoFd::operator*() const
{
    return get();
}
