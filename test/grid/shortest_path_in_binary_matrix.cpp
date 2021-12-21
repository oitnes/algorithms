#include "grid/shortest_path_in_binary_matrix.hpp"

#include <gtest/gtest.h>

using namespace std;
using namespace shortest_path_in_binary_matrix;

TEST(ShortestPathInBinaryMatrix, basic_1) {
    vector<vector<int>> input{{0, 0, 0, 0, 0},
                             {1, 0, 0, 0, 0},
                             {1, 1, 0, 0, 0},
                             {1, 1, 1, 0, 0},
                             {1, 1, 1, 1, 0}};
    auto result = solve(input);
    GTEST_ASSERT_EQ(result, 5);
}