#include "exceptions.hpp"

ErrnoException::ErrnoException(const int errnum)
    : _errnum(errnum), _message("Errno " + std::to_string(_errnum) + ": " + std::strerror(_errnum))
{
}

const char *ErrnoException::what() const noexcept
{
    return _message.c_str();
}
