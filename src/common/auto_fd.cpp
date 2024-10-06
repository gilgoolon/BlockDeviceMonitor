#include "auto_fd.hpp"

AutoFd make_auto_fd(const int fd)
{
    return AutoFd(fd != UNIX_INT_ERROR_VALUE ? new int(fd) : nullptr);
}
