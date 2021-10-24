#include "../str_view/lambda/str_view.hpp"
#include "gtest/gtest.h"

// Def. Ctor
TEST(SV_Empty, SV_Ctor)
{
    lambda::str_view v;

    EXPECT_TRUE(v.empty());
    EXPECT_EQ(v.size(), 0);
    EXPECT_EQ(v.data(), nullptr);
}

// Copy Ctor
TEST(SV_Cpy, SV_Ctor)
{
    lambda::str_view v0("123");
    lambda::str_view v1(v0);

    EXPECT_EQ(v0.size(), v1.size());
    EXPECT_EQ(v0.data(), v1.data());
}

TEST(CppRefSV_Cpy, SV_Ctor)
{
    // constexpr lambda::str_view wcstr_v("asdas");
}
