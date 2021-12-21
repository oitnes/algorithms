#include "array/minimum_size_subarray_sum.hpp"

#include <gtest/gtest.h>

using namespace std;
using namespace minimum_size_subarray_sum;

TEST(MinimumSizeSubarraySum, basic_1) {
    vector<int> input{2,3,1,2,4,3};
    auto result = min(7, input);
    GTEST_ASSERT_EQ(result, 2);
}