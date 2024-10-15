#include "auto_fd.hpp"
#include "../os_utils.hpp"

Autos::AutoFd::AutoFd(const int fd)
    : _fd(fd)
{
}

Autos::AutoFd::AutoFd(const AutoFd&& fd)
{
    _fd = fd._fd;
}

Autos::AutoFd& Autos::AutoFd::operator=(const AutoFd&& fd)
{
    _fd = fd._fd;
    return *this;
}

Autos::AutoFd::~AutoFd()
{
    try {
        if (OS::UNIX_INT_ERROR_VALUE != _fd) {
            OS::covered_call(::close, _fd);
        }
    } catch (...) {
    }
}

int Autos::AutoFd::get() const
{
    return _fd;
}

int Autos::AutoFd::operator*() const
{
    return get();
}
