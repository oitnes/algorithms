#include "array/3sum.hpp"

#include "../tools.hpp"

#include <gtest/gtest.h>

using namespace std;
using namespace three_sum;

TEST(ThreeSum, basic_1) {
    vector<int> input{-1, 0, 1, 2, -1, -4};
    auto result = threeSum(input);
    vector<vector<int>> target{{-1, -1, 2},
                               {-1, 0,  1}};
    CHECK_EQUAL_MAPS(result, target)
}