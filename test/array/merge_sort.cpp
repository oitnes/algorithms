#include "array/merge_sort.hpp"

#include "../tools.hpp"

#include <gtest/gtest.h>

using namespace std;
using namespace merge_sort;

TEST(MergeSort, basic_1_int_increase) {
    vector<int> input{1, 2, 9, 7, 0, 12, 4, 5};
    sort(input, [](int a, int b) { return a < b; });
    vector<int> target{0, 1, 2, 4, 5, 7, 9, 12};
    CHECK_EQUAL_ARRAYS(target, input);
}

TEST(MergeSort, basic_1_int_decrease) {
    vector<int> input{1, 2, 9, 7, 0, 12, 4, 5};
    sort(input, [](int a, int b) { return a > b; });
    vector<int> target{12, 9, 7, 5, 4, 2, 1, 0};
    CHECK_EQUAL_ARRAYS(target, input);
}

TEST(MergeSort, basic_1_double_increase) {
    vector<double> input{1.1, 2.8, 9.0, 7.4, 0.002, 12.1, 4.9, 5.32};
    sort(input, [](double a, double b) { return a < b; });
    vector<double> target{0.002, 1.1, 2.8, 4.9, 5.32, 7.4, 9.0, 12.1};
    CHECK_EQUAL_ARRAYS(target, input);
}

TEST(MergeSort, basic_1_double_decrease) {
    vector<double> input{1.1, 2.8, 9.0, 7.4, 0.002, 12.1, 4.9, 5.32};
    sort(input, [](double a, double b) { return a > b; });
    vector<double> target{12.1, 9.0, 7.4, 5.32, 4.9, 2.8, 1.1, 0.002};
    CHECK_EQUAL_ARRAYS(target, input);
}

TEST(MergeSort, basic_2_int_increase) {
    vector<int> input{31, 41, 56, 26, 41, 58};
    sort(input, [](int a, int b) { return a < b; });
    vector<int> target{26, 31, 41, 41, 56, 58};
    CHECK_EQUAL_ARRAYS(target, input);
}

TEST(MergeSort, basic_2_int_decrease) {
    vector<int> input{31, 41, 56, 26, 41, 58};
    sort(input, [](int a, int b) { return a > b; });
    vector<int> target{58, 56, 41, 41, 31, 26};
    CHECK_EQUAL_ARRAYS(target, input);
}
