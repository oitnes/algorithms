#include "string/generate_parentheses.hpp"

#include "../tools.hpp"

#include "gtest/gtest.h"

using namespace std;
using namespace generate_parentheses;

TEST(GenerateParentheses, basic_1) {
    auto result = generate(3);

    vector<string> target{"((()))", "(()())", "(())()", "()(())", "()()()"};
    CHECK_EQUAL_ARRAYS(result, target);
}