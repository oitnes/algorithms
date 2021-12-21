#include "graph/number_of_provinces.hpp"

#include <gtest/gtest.h>

using namespace std;
using namespace number_of_provinces;

TEST(NumberOfProvinces, basic_1) {
    vector<vector<int>> input{{1, 1, 0},
                              {1, 1, 0},
                              {0, 0, 1}};
    auto result = find(input);
    GTEST_ASSERT_EQ(result, 2);
}