#include "set/permutations_2.hpp"

#include "../tools.hpp"

#include <gtest/gtest.h>

using namespace std;
using namespace permutations_two;

TEST(PermutationsTwo, basic_1) {
    vector<int> input{1, 1, 2};
    auto result = permuteUnique(input);
    vector<vector<int>> target{{1, 1, 2},
                               {1, 2, 1},
                               {2, 1, 1}};
    CHECK_EQUAL_MAPS(result, target)
}

TEST(PermutationsTwo, basic_2) {
    vector<int> input{1, 1};
    auto result = permuteUnique(input);
    vector<vector<int>> target{{1, 1}};
    CHECK_EQUAL_MAPS(result, target)
}
