#include "array/find_minimum_in_rotated_sorted_array.hpp"

#include <gtest/gtest.h>

using namespace std;
using namespace find_minimum_in_rotated_sorted_array;

TEST(FindMinimumInRotatedSortedArray, basic_1) {
    vector<int> input{3,4,5,1,2};
    auto c = find(input);
    GTEST_ASSERT_EQ(c, 1);
}
