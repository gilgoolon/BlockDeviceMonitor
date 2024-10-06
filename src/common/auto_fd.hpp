#pragma once
#include <memory>
#include <unistd.h>

#include "unix.hpp"

struct FdCloser final
{
    void operator()(const int *fd) const
    {
        if (UNIX_INT_ERROR_VALUE != *fd)
        {
            ::close(*fd);
        }
    }
};

using AutoFd = std::unique_ptr<int, FdCloser>;

AutoFd make_auto_fd(int fd);
