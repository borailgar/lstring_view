## lstring_view

#### C++11/14 compatible header-only **std::string_view** implementation       
  - Compile time evaluation: 
  ```c++
    using namespace lambda::sv_literals;

    constexpr auto ex0 = "ExampleSV"_sv;
    static_assert(ex0.size() > 1, "");

    constexpr auto ex1 = "Example2SV"_sv;
    static_assert(ex1.size() > 1, "");
```

  - Extended for some of C++ 20 std::string_view features :
  
      - **starts_with(const CharT*), 
      - **ends_with(const CharT*) 
 ```c++
    constexpr lambda::str_view uri = "http://example.com"_sv;
    /*constexpr */ auto res = uri.starts_with("http");

    if (uri.starts_with("http"))
    {
        // ...
    }
    else{}
```

**TODO :**
  - unit-tests!
  - Compile time string concatenating? 
    

    

    
