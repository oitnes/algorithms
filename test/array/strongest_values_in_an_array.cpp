#include "array/strongest_values_in_an_array.hpp"

#include <gtest/gtest.h>

#include "../tools.hpp"

using namespace std;
using namespace strongest_values_in_an_array;

TEST(StrongestValuesInAnArray, basic_1) {
    vector<int> input{1,2,3,4,5};
    auto result = getStrongest(input, 2);
    vector<int> target{5,1};
    CHECK_EQUAL_ARRAYS(result, target);
}