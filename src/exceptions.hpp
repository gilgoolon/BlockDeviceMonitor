#pragma once
#include <stdexcept>
#include <string>
#include <cstring>
#include <cerrno>
#include <sstream>
#define DEFINE_EXCEPTION_CODES       \
    ENUM_CODE(ErrnoException)        \
    ENUM_CODE(InvalidArgument)       \
    ENUM_CODE(DisconnectedException) \
    ENUM_CODE(InvalidFile)           \
    ENUM_CODE(RuntimeError)          \
    ENUM_CODE(MissingInformation)

// Macro to define the enum
#define ENUM_CODE(code) code,

// Create the enum using the macro
enum class ExceptionCode : uint32_t
{
    DEFINE_EXCEPTION_CODES
};

#undef ENUM_CODE
// Macro to generate the to_string function
#define ENUM_CODE(code)       \
    case ExceptionCode::code: \
        return #code;

inline std::string to_string(ExceptionCode code)
{
    switch (code)
    {
        DEFINE_EXCEPTION_CODES
    default:
        throw std::invalid_argument(std::string("invalid ExceptionCode value ") + std::to_string(static_cast<uint32_t>(code)) + " passed to to_string(ExceptionCode)");
    }
}

class Exception
{
public:
    explicit Exception(ExceptionCode code, const std::string &message);

    virtual std::string what() const;

    ExceptionCode code() const noexcept;

private:
    ExceptionCode _code;
    std::string _message;
};

class ErrnoException final : public Exception
{
public:
    ErrnoException(int errnum = errno);
};
