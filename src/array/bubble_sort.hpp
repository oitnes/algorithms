#pragma once

#include <vector>
#include <functional>

namespace bubble_sort {

    template<typename T>
    void sort(std::vector<T> &input, const std::function<bool(T, T)> &comparator) {
        for (int i = 0; i < input.size(); i++) {
            for (int j = input.size() - 1; j > i; j--) {
                if (comparator(input[j], input[j - 1]))
                    std::swap(input[j], input[j - 1]);
            }
        }
    }

    template<typename T, typename F>
    void sort(std::vector<T> &input, F comparator) {
        return bubble_sort::sort(input, static_cast<const std::function<bool(T, T)> &>(comparator));
    }

}