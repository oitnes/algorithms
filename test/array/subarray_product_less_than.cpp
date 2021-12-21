#include "array/subarray_product_less_than.hpp"

#include <gtest/gtest.h>

using namespace std;
using namespace subarray_product_less_than;

TEST(SubarrayProductLessThan, basic_1) {
    vector<int> input{10,5,2,6};
    auto result = calc(input, 100);
    GTEST_ASSERT_EQ(result, 8);
}