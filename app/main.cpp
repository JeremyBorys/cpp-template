#include <hello.h>

#include <fmt/format.h>

#include <algorithm>

using namespace fmt::literals;

auto main(int /*argc*/, char * /*argv*/[]) -> int
{
    fmt::print("{} world! - {}", hello::message());
    return 0;
}