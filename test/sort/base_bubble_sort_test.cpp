#include "tools.hpp"
#include "sort/bubble_sort.hpp"

#include <gtest/gtest.h>


TEST(BubbleSort, basic_1_int_increase) {
    std::vector a = {1, 2, 9, 7, 0, 12, 4, 5};
    bubble_sort::sort(a, [](int a, int b) { return a < b; });

    std::vector target = {0, 1, 2, 4, 5, 7, 9, 12};

    CHECK_EQUAL_ARRAYS(target, a);
}

TEST(BubbleSort, basic_1_int_decrease) {
    std::vector a = {1, 2, 9, 7, 0, 12, 4, 5};
    bubble_sort::sort(a, [](int a, int b) { return a > b; });

    std::vector target = {12, 9, 7, 5, 4, 2, 1, 0};

    CHECK_EQUAL_ARRAYS(target, a);
}

TEST(BubbleSort, basic_1_double_increase) {
    std::vector a{1.1, 2.8, 9.0, 7.4, 0.002, 12.1, 4.9, 5.32};
    bubble_sort::sort(a, [](double a, double b) { return a < b; });

    std::vector target{0.002, 1.1, 2.8, 4.9, 5.32, 7.4, 9.0, 12.1};

    CHECK_EQUAL_ARRAYS(target, a);
}

TEST(BubbleSort, basic_1_double_decrease) {
    std::vector a = {1.1, 2.8, 9.0, 7.4, 0.002, 12.1, 4.9, 5.32};
    bubble_sort::sort(a, [](double a, double b) { return a > b; });

    std::vector target = {12.1, 9.0, 7.4, 5.32, 4.9, 2.8, 1.1, 0.002};

    CHECK_EQUAL_ARRAYS(target, a);
}

TEST(BubbleSort, basic_2_int_increase) {
    std::vector a = {31, 41, 56, 26, 41, 58};
    bubble_sort::sort(a, [](int a, int b) { return a < b; });

    std::vector target = {26, 31, 41, 41, 56, 58};

    CHECK_EQUAL_ARRAYS(target, a);
}

TEST(BubbleSort, basic_2_int_decrease) {
    std::vector a = {31, 41, 56, 26, 41, 58};
    bubble_sort::sort(a, [](int a, int b) { return a > b; });

    std::vector target = {58, 56, 41, 41, 31, 26};

    CHECK_EQUAL_ARRAYS(target, a);
}
