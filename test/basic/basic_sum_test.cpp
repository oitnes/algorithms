#include "basic/basic_sum.hpp"

#include <gtest/gtest.h>
#include <iostream>

TEST(Basic, sum) {
    auto result = basic::sum(5, 9);

    EXPECT_EQ(result, 14);
}