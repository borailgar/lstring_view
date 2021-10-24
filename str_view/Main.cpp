#include "lambda/str_view.h"
#include <iostream>
#include <string>

int main()
{
#if 0
    using namespace lambda::sv_literals;
    auto rra = "ExampleSV"_sv;
    auto rra2 = "ExampleSV"_sv;

    auto is_eq = rra == rra2;
    std::cout << std::boolalpha << is_eq << std::endl;
    std::cout << rra << std::endl;

    std::string as{"ass"};
    lambda::str_view asd = as;

    std::cout << asd << std::endl;
#endif
    return 0;
}
