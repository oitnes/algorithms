#include "array/find_the_town_judge.hpp"

#include <gtest/gtest.h>

using namespace std;
using namespace find_the_town_judge;

TEST(FindTheTownJudge, basic_1) {
    vector<vector<int>> input{{1, 2}};
    auto c = findJudge(2, input);
    GTEST_ASSERT_EQ(c, 2);
}
