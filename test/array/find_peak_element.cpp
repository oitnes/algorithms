#include "array/find_peak_element.hpp"

#include <gtest/gtest.h>

using namespace std;
using namespace find_peak_element;

TEST(FindPeakElement, basic_1) {
    vector<int> input{1, 2, 3, 1};
    auto c = findPeakElement(input);
    GTEST_ASSERT_EQ(c, 2);
}
