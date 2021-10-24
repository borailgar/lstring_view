#include "lambda/str_view.hpp"
#include <iostream>

int main()
{
    constexpr lambda::str_view str = "asd";

    using namespace lambda::sv_literals;

    constexpr lambda::str_view ex0 = "ExampleSV"_sv;
    static_assert(ex0.size() > 1, "");

    constexpr auto ex1 = "Example2SV"_sv;
    static_assert(ex1.size() > 1, "");

    auto is_eq = ex0 == ex1;

    return 0;
}
