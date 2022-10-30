#include "array/product_expect_self.hpp"

#include "../tools.hpp"

#include <gtest/gtest.h>

using namespace std;
using namespace product_expect_self;

TEST(ProductExpectSelf, basic_1) {
    vector<int> input{1,2,3,4}, target{24,12,8,6};
    auto result = calc(input);
    CHECK_EQUAL_ARRAYS(result, target);
}

TEST(ProductExpectSelf, basic_2) {
    vector<int> input{-1,1,0,-3,3}, target{0,0,9,0,0};
    auto result = calc(input);
    CHECK_EQUAL_ARRAYS(result, target);
}
