#include "set/subset.hpp"

#include "../tools.hpp"

#include <gtest/gtest.h>

using namespace std;
using namespace subset;

TEST(Subset, basic_1) {
    vector<int> input{1, 2, 3};
    auto result = subsets(input);
    vector<vector<int>> target{{},
                               {1},
                               {2},
                               {3},
                               {1, 2},
                               {1, 3},
                               {2, 3},
                               {1, 2, 3}};
    CHECK_EQUAL_MAPS(result, target)
}
