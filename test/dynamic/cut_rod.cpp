#include "dynamic/cut_rod.hpp"

#include <gtest/gtest.h>

using namespace std;
using namespace cut_rod;

TEST(CutRod, basic_1) {
    vector<int> input{1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
    auto result = solveFull(input, 4);
    GTEST_ASSERT_EQ(result, 10);
}

TEST(CutRod, basic_2) {
    vector<int> input{1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
    auto result = solveDynamic(input, 4);
    GTEST_ASSERT_EQ(result, 10);
}