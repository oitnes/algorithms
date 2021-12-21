#include "grid/number_of_islands.hpp"

#include <gtest/gtest.h>

using namespace std;
using namespace number_of_islands;

TEST(NumberOfIslands, basic_1) {
    vector<vector<char>> input{{'1', '1', '1', '1', '0'},
                               {'1', '1', '0', '1', '0'},
                               {'1', '1', '0', '0', '0'},
                               {'0', '0', '0', '0', '0'}};
    auto result = calc(input);
    GTEST_ASSERT_EQ(result, 1);
}