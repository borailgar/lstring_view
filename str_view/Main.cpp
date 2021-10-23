#include "lambda/str_view.h"
#include <iostream>
#include <string>

int main()
{
    using namespace lambda::sv_literals;
    auto rra = "ExampleSV"_sv;
    auto rra2 = "ExampleSV"_sv;

    auto is_eq = rra == rra2;
    std::cout << std::boolalpha << is_eq << std::endl;
    std::cout << rra << std::endl;

    return 0;
}
