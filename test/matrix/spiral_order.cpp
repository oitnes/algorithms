#include "matrix/spiral_order.hpp"

#include "../tools.hpp"

#include <gtest/gtest.h>

using namespace std;
using namespace spiral_order;

TEST(SpiralOrder, basic_1) {
    vector<vector<int>> input{{1,2,3},{4,5,6},{7,8,9}};
    auto result = spiralOrder(input);
    vector<int> target{1,2,3,6,9,8,7,4,5};
    CHECK_EQUAL_ARRAYS(result, target);
}

