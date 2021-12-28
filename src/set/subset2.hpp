#pragma once

#include <vector>
#include <algorithm>

// https://leetcode.com/problems/subsets-ii/
namespace subset_two {

    namespace {

        void deep(std::vector<std::vector<int>> &result, const std::vector<int> &nums,
                  const std::vector<int> &last_layer_subset, int idx, int layer, int lenght) noexcept {
            if (lenght == layer) {
                return result.push_back(last_layer_subset);
            }
            for (int i = idx; i <= nums.size() - lenght + layer; i++) {
                if (i - idx > 0 && nums[i] == nums[i - 1])
                    continue;
                std::vector<int> current_subset(last_layer_subset);
                current_subset.push_back(nums[i]);
                deep(result, nums, current_subset, i + 1, layer + 1, lenght);
            }
        }

    }

    std::vector<std::vector<int>> subsets(std::vector<int> &nums) {
        sort(nums.begin(), nums.end());
        std::vector<std::vector<int>> result;
        std::vector<int> zero;
        for (int lenght = 0; lenght <= nums.size(); lenght++)
            deep(result, nums, zero, 0, 0, lenght);
        return result;
    }

}
