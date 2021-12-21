#pragma once

#include <vector>

// https://leetcode.com/problems/minimum-size-subarray-sum/
namespace minimum_size_subarray_sum {

    int min(int target, std::vector<int> &nums) {
        auto last_min_size = std::numeric_limits<int>::max();
        for (int i = 0, j = 0, i_sum = 0, j_sum = 0; j < nums.size(); j++) {
            j_sum += nums[j];
            while ((j_sum - i_sum) >= target) {
                last_min_size = std::min(last_min_size, j - i + 1);
                i_sum += nums[i++];
            }
        }
        return (last_min_size != std::numeric_limits<int>::max()) ? last_min_size : 0;
    }

}