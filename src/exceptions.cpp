#include "exceptions.hpp"

ErrnoException::ErrnoException(const int errnum)
    : Exception(ExceptionCode::ErrnoException, "Errno " + std::to_string(errnum) + ": " + std::strerror(errnum))
{
}

Exception::Exception(ExceptionCode code, const std::string &message)
    : _code(code), _message(message)
{
}

std::string Exception::what() const
{
    return to_string(_code) + ": " + _message;
}

ExceptionCode Exception::code() const noexcept
{
    return _code;
}
