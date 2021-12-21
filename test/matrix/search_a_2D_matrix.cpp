#include "matrix/search_a_2D_matrix.hpp"

#include <gtest/gtest.h>

using namespace std;
using namespace search_a_2d_matrix;

TEST(SearchA2DMatrix, basic_1) {
    vector<vector<int>> input{{1,  3,  5,  7},
                              {10, 11, 16, 20},
                              {23, 30, 34, 60}};
    GTEST_ASSERT_TRUE(search(input, 3));
}
