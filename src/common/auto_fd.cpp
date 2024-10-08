#include "auto_fd.hpp"
#include "utils.hpp"

AutoFd make_auto_fd(const int fd)
{
    return AutoFd(fd != os::UNIX_INT_ERROR_VALUE ? new int(fd) : nullptr);
}

void FdCloser::operator()(const int *fd) const
{
    try
    {

        if (os::UNIX_INT_ERROR_VALUE != *fd)
        {
            os::covered_call(::close, *fd);
        }
    }
    catch (...)
    {
        // destructor... should log error here when logging mechanism is implemented
    }
}
