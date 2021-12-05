#pragma once

#include <vector>
#include <functional>

namespace merge_sort {

    namespace {

        // q - separator between two sub arrays
        template<typename T>
        void merge(std::vector<T> &input, const std::function<bool(T, T)> &comparator, int p, int q, int r) {
            std::vector<T> left_part{input.begin() + p, input.begin() + q + 1};
            const auto right_end = (r < input.size()) ? (input.begin() + r + 1) : input.end();
            std::vector<T> right_part{input.begin() + q + 1, right_end};

            for (int k = p, i = 0, j = 0; k <= r; k++) {
                if ((left_part.size() > i) && (right_part.size() > j)) {
                    input[k] = (comparator(left_part[i], right_part[j])) ? left_part[i++] : right_part[j++];
                } else {
                    input[k] = (left_part.size() > i) ? left_part[i++] : right_part[j++];
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
        return merge_sort(input, comparator, 0, input.size() - 1);
    }

    template<typename T, typename F>
    void sort(std::vector<T> &input, F comparator) {
        return merge_sort::sort(input, static_cast<const std::function<bool(T, T)> &>(comparator));
    }

}