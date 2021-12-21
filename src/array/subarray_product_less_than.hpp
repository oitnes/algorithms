#pragma once

#include <vector>

// https://leetcode.com/problems/subarray-product-less-than-k/
namespace subarray_product_less_than {

    int calc(std::vector<int> &nums, int k) {
        auto counter = 0;
        if (k > 1) {
            for (auto i = 0, j = 0, current_value = 1; j < nums.size(); j++) {
                current_value *= nums[j];
                while (current_value >= k) {
                    current_value /= nums[i++];
                }
                counter += j - i + 1;
            }
        }
        return counter;
    }

}