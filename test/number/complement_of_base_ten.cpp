#include "number/complement_of_base_ten.hpp"

#include <gtest/gtest.h>

using namespace std;
using namespace complement_of_base_ten;

TEST(ComplementOfBaseTen, basic_1) {
    auto result = bitwiseComplement(5);
    GTEST_ASSERT_EQ(result, 2);
}

TEST(ComplementOfBaseTen, basic_2) {
    auto result = bitwiseComplement(7);
    GTEST_ASSERT_EQ(result, 0);
}

TEST(ComplementOfBaseTen, basic_3) {
    auto result = bitwiseComplement(10);
    GTEST_ASSERT_EQ(result, 5);
}
