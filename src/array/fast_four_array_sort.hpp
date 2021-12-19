#pragma once

#include <vector>
#include <functional>

namespace fast_four_size_array_sort {

    template<typename T>
    void sort(int &a, int &b, int &c, int &d, const std::function<bool(T, T)> &comparator) {
        if (comparator(b, a)) // 1
            std::swap(b, a);
        if (comparator(d, c)) // 2
            std::swap(d, c);
        if (comparator(d, b)) // 3
            std::swap(d, b);
        if (comparator(c, a)) // 4
            std::swap(c, a);
        if (comparator(c, b)) // 5
            std::swap(c, b);
    }

    template<typename T, typename F>
    void sort(std::vector<T> &input, F comparator) {
        assert(input.size() == 4);
        return fast_four_size_array_sort::sort(input[0], input[1], input[2], input[3],
                                               static_cast<const std::function<bool(T, T)> &>(comparator));
    }

}