#include "string/find_all_anagrams_in_string.hpp"

#include "../tools.hpp"

#include <gtest/gtest.h>

using namespace std;
using namespace find_all_anagrams_in_string;

TEST(FindAllAnagramsInString, basic_1) {
    string input = "cbaebabacd";
    string input_sub = "abc";
    auto result = find(input, input_sub);
    vector<int> target{0, 6};
    CHECK_EQUAL_ARRAYS(result, target)
}
