#include "lambda/str_view.h"
#include <string>

int main()
{
    using namespace std::string_literals;
    auto rr = "Asdasd"s;

    using namespace lambda::sv_literals;
    auto rra = "Asdasd"_sv;

    return 0;
}
