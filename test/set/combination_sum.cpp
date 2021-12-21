#include "set/combination_sum.hpp"

#include "../tools.hpp"

#include <gtest/gtest.h>

using namespace std;
using namespace combination_sum;

TEST(CombinationSum, basic_1) {
    vector<int> input{2,3,5};
    auto result = combinationSum(input, 8);
    vector<vector<int>> target{{2,2,2,2},
                               {2,3,3},
                               {3,5}};
    CHECK_EQUAL_MAPS(result, target)
}
