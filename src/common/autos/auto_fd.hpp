#pragma once
#include <memory>
#include <unistd.h>

namespace Autos
{

    class AutoFd final
    {
    public:
        explicit AutoFd(const int fd);

        AutoFd(const AutoFd &fd) = delete;

        AutoFd(const AutoFd &&fd);

        AutoFd &operator=(const AutoFd &fd) = delete;

        AutoFd &operator=(const AutoFd &&fd);

        ~AutoFd();

        int get() const;

        int operator*() const;

    private:
        int _fd;
    };
};
