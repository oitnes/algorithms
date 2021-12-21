#include "grid/word_search.hpp"

#include <gtest/gtest.h>

using namespace std;
using namespace word_search;

TEST(WordSearch, basic_1) {
    vector<vector<char>> input{{'A', 'B', 'C', 'E'},
                               {'S', 'F', 'C', 'S'},
                               {'A', 'D', 'E', 'E'}};
    string input_word("ABCB");
    GTEST_ASSERT_FALSE(exist(input, input_word));
}

TEST(WordSearch, basic_2) {
    vector<vector<char>> input{{'A', 'A', 'A', 'A'},
                               {'A', 'A', 'A', 'A'},
                               {'A', 'A', 'A', 'A'}};
    string input_word("AAAAAAAAAAAAA");
    GTEST_ASSERT_FALSE(exist(input, input_word));
}
