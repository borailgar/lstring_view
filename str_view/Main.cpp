#include "lambda/str_view.hpp"
#include <iostream>

int main()
{
    using namespace lambda::sv_literals;

    constexpr lambda::str_view ex0 = "ExampleSV"_sv;
    static_assert(ex0.size() > 1, "");

    constexpr auto ex1 = "Example2SV"_sv;
    static_assert(ex1.size() > 1, "");

    const auto cmp_res = ex0.compare(ex1);
    std::cout << cmp_res << std::endl;

    return 0;
}
