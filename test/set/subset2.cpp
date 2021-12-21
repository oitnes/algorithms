#include "set/subset2.hpp"

#include "../tools.hpp"

#include <gtest/gtest.h>

using namespace std;
using namespace subset_two;

TEST(SubsetTwo, basic_1) {
    vector<int> input{1, 2, 2};
    auto result = subsets(input);
    vector<vector<int>> target{{},
                               {1},
                               {2},
                               {1, 2},
                               {2, 2},
                               {1, 2, 2}};
    CHECK_EQUAL_MAPS(result, target)
}
