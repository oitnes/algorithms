#include "graph/all_paths_from_source_to_target.hpp"

#include <gtest/gtest.h>

#include "../tools.hpp"

using namespace std;
using namespace all_paths_from_source_to_target;

TEST(AllPathsFromSourceToTarget, basic_1) {
    vector<vector<int>> m = {{1, 2},
                             {3},
                             {3},
                             {}};
    auto result = find(m);
    vector<vector<int>> target = {{0, 1, 3},
                                  {0, 2, 3}};
    CHECK_EQUAL_MAPS(result, target);
}