#include "grid/surrounded_regions.hpp"

#include "../tools.hpp"

#include <gtest/gtest.h>

using namespace std;
using namespace surrounded_region;

TEST(SurroundedRegions, basic_1) {
    vector<vector<char>> input{{'X', 'X', 'X', 'X', 'X'},
                               {'X', 'O', 'O', 'O', 'X'},
                               {'X', 'X', 'O', 'O', 'X'},
                               {'X', 'X', 'X', 'O', 'X'},
                               {'X', 'O', 'X', 'X', 'X'}};
    solve(input);
    vector<vector<char>> target{{'X', 'X', 'X', 'X', 'X'},
                                {'X', 'X', 'X', 'X', 'X'},
                                {'X', 'X', 'X', 'X', 'X'},
                                {'X', 'X', 'X', 'X', 'X'},
                                {'X', 'O', 'X', 'X', 'X'}};
    CHECK_EQUAL_MAPS(input, target);
}

TEST(SurroundedRegions, basic_2) {
    vector<vector<char>> input{{'O', 'O'},
                               {'O', 'O'}};
    solve(input);
    vector<vector<char>> target{{'O', 'O'},
                                {'O', 'O'}};
    CHECK_EQUAL_MAPS(input, target);
}

TEST(SurroundedRegions, basic_3) {
    vector<vector<char>> input{{'X', 'X', 'X', 'X'},
                               {'X', 'O', 'O', 'X'},
                               {'X', 'X', 'O', 'X'},
                               {'X', 'O', 'X', 'X'}};
    solve(input);
    vector<vector<char>> target{{'X', 'X', 'X', 'X'},
                                {'X', 'X', 'X', 'X'},
                                {'X', 'X', 'X', 'X'},
                                {'X', 'O', 'X', 'X'}};
    CHECK_EQUAL_MAPS(input, target);
}