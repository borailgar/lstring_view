## str_view

- C++11/14 compatible string_view implementation.
  - Contains some of C++20 string_view features
    - starts_with()
    - ends_with()
    
```c++
    constexpr lambda::str_view str = "asd";

    using namespace lambda::sv_literals;

    constexpr lambda::str_view ex0 = "ExampleSV"_sv;
    static_assert(ex0.size() > 1, "");

    constexpr auto ex1 = "Example2SV"_sv;
    static_assert(ex1.size() > 1, "");

```
    
