#pragma once
#include <exception>
#include <string>
#include <cstring>
#include <cerrno>
#include <sstream>

class ErrnoException final : public std::exception
{
public:
    ErrnoException(int errnum = errno);

    const char *what() const noexcept override;

private:
    const int _errnum;
    const std::string _message;
};

class DisconnectedException final : public std::exception
{
};
