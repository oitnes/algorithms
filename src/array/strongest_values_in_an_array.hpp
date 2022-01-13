#pragma once

#include <vector>
#include <functional>

// https://leetcode.com/problems/the-k-strongest-values-in-an-array/
namespace strongest_values_in_an_array {

    std::vector<int> getStrongest(std::vector<int> &arr, int k) {
        sort(arr.begin(), arr.end());
        std::vector<int> r;
        int j = 0, i = arr.size() - 1, m = arr[((arr.size() - 1) / 2)];
        while (r.size() != k && j <= i) {
            r.push_back(((abs(arr[j] - m) > abs(arr[i] - m)) ? arr[j++] : arr[i--]));
        }
        return r;
    }

}