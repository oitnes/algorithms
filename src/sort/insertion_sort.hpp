#pragma once

#include <vector>
#include <functional>

namespace insertion_sort {

    template<typename T>
    void sort(std::vector<T> &input, const std::function<bool(T, T)> &comparator) {
        for (int i = 1; i < input.size(); i++) {
            T key_value = input[i];
            int j = i - 1;
            for (; (j >= 0) && comparator(key_value, input[j]); j--) {
                input[j + 1] = input[j];
            }
            input[j + 1] = key_value;
        }
    }

    template<typename T, typename F>
    void sort(std::vector<T> &input, F comparator) {
        return sort(input, static_cast<const std::function<bool(T, T)> &>(comparator));
    }

}