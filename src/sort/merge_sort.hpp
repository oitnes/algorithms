#pragma once

#include <vector>
#include <functional>

namespace merge_sort {

    namespace {
        // q - separator between two sub arrays
        template<typename T>
        void merge(std::vector<T> &input, const std::function<bool(T, T)> &comparator, int p, int q, int r) {
            auto sep_value = std::numeric_limits<T>::max();
            if (comparator(sep_value, std::numeric_limits<T>::min()))
                sep_value = std::numeric_limits<T>::min();

            std::vector<T> L{input.begin() + p, input.begin() + q + 1};
            L.push_back(sep_value);
            auto right_end = input.end();
            if (r < input.size())
                right_end = input.begin() + r + 1;
            std::vector<T> R{input.begin() + q + 1, right_end};
            R.push_back(sep_value);

            for (int k = p, i = 0, j = 0; k <= r; k++) {
                if (comparator(L[i], R[j])) {
                    input[k] = L[i++];
                } else {
                    input[k] = R[j++];
                }
            }
        }

        template<typename T>
        void merge_sort(std::vector<T> &input, const std::function<bool(T, T)> &comparator, int p, int r) {
            if (p < r) {
                int q = (p + r) / 2;
                merge_sort(input, comparator, p, q);
                merge_sort(input, comparator, q + 1, r);
                merge(input, comparator, p, q, r);
            }
        }

    }

    template<typename T>
    void sort(std::vector<T> &input, const std::function<bool(T, T)> &comparator) {
        return merge_sort(input, comparator, 0, input.size()-1);
    }

    template<typename T, typename F>
    void sort(std::vector<T> &input, F comparator) {
        return sort(input, static_cast<const std::function<bool(T, T)> &>(comparator));
    }

}