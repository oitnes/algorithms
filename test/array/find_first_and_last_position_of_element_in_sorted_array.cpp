#include "array/find_first_and_last_position_of_element_in_sorted_array.hpp"

#include "../tools.hpp"

#include <gtest/gtest.h>

using namespace std;
using namespace find_first_and_last_position_of_element_in_sorted_array;

TEST(FindFirstAndLastPositionOfElementInSortedArray, basic_1) {
    vector<int> input{5,7,7,8,8,10};
    auto result = search(input, 8);
    auto target = make_pair(3,4);
    CHECK_EQUAL_PAIRS(result, target)
}
