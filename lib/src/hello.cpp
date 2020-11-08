#include "hello.h"

auto hello::message() noexcept -> const char *
{
    return "Hello";
}
