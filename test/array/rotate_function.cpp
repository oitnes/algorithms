#include "array/rotate_function.hpp"

#include <gtest/gtest.h>

using namespace std;
using namespace rotate_function;

TEST(RotateFunction, basic_1){
    vector<int> input{4,3,2,6};
    auto result = maxRotateFunction(input);
    GTEST_ASSERT_EQ(result, 26);
}