#include "array/search_in_rotated_sorted_array.hpp"

#include <gtest/gtest.h>

using namespace std;
using namespace search_in_rotated_binary_array;

TEST(SearchInRotatedSortedArray, basic_1) {
    vector<int> input{4, 5, 6, 7, 0, 1, 2};
    auto c = search(input, 0);
    GTEST_ASSERT_EQ(c, 4);
}
