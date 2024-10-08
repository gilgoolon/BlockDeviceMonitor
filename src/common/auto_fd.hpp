#pragma once
#include <memory>
#include <unistd.h>

#include "unix.hpp"

struct FdCloser final
{
    void operator()(const int *fd) const;
};

using AutoFd = std::unique_ptr<int, FdCloser>;

AutoFd make_auto_fd(int fd);
