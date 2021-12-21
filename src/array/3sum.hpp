#pragma once

#include <vector>
#include <functional>

// https://leetcode.com/problems/3sum/
namespace three_sum {

    std::vector<std::vector<int>> threeSum(std::vector<int> &nums) {
        sort(nums.begin(), nums.end());
        std::vector<std::vector<int>> result;
        for (int i = 0, j = 0, k = 0; i < nums.size(); i++) {
            const int &num_i = nums[i];
            if (i && num_i == nums[i - 1])
                continue;
            for (int j = i + 1, k = nums.size() - 1; j < k;) {
                const int &num_j = nums[j];
                const int &num_k = nums[k];
                if (num_i + num_j + num_k < 0) {
                    j++;
                } else if (num_i + num_j + num_k > 0) {
                    k--;
                } else {
                    result.emplace_back(std::vector<int>{num_i, num_j, num_k});
                    for (int iter = num_j; (j < k && nums[j] == iter); j++)
                        continue;
                    for (int iter = num_k; (j < k && nums[k] == iter); k--)
                        continue;
                }
            }
        }
        return result;
    }

}