#include "array/fast_four_array_sort.hpp"

#include "../tools.hpp"

#include <gtest/gtest.h>

using namespace std;
using namespace fast_four_size_array_sort;

TEST(FastFourArraySort, basic_1) {
    vector<int> input{0, 1, 2, 3};
    sort(input, [](int a, int b) { return a < b; });
    vector target{0, 1, 2, 3};

    CHECK_EQUAL_ARRAYS(target, input);
}

TEST(FastFourArraySort, basic_2) {
    vector<int> input{1, 2, 3, 0};
    sort(input, [](int a, int b) { return a < b; });
    vector<int> target{0, 1, 2, 3};
    CHECK_EQUAL_ARRAYS(target, input);
}

TEST(FastFourArraySort, basic_3) {
    vector<int> input{1, 0, 3, 2};
    sort(input, [](int a, int b) { return a < b; });
    vector<int> target{0, 1, 2, 3};
    CHECK_EQUAL_ARRAYS(target, input);
}

TEST(FastFourArraySort, basic_4) {
    vector<int> input{3, 2, 1, 0};
    sort(input, [](int a, int b) { return a < b; });
    vector<int> target{0, 1, 2, 3};
    CHECK_EQUAL_ARRAYS(target, input);
}