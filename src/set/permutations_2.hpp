#pragma once

#include <vector>
#include <algorithm>

// https://leetcode.com/problems/permutations-ii/
namespace permutations_two {

    namespace {

        void f(const std::vector<int> &nums, std::vector<int> &current, std::vector<std::vector<int>> &result,
               std::vector<bool> &used_indexes, int N) {
            if (current.size() == N) {
                result.push_back(current);
                return;
            }
            for (int i = 0; i < N; i++) {
                if (used_indexes[i])
                    continue;
                used_indexes[i] = true;
                current.push_back(nums[i]);
                f(nums, current, result, used_indexes, N);
                current.pop_back();
                used_indexes[i] = false;
                while (i + 1 < N && nums[i] == nums[i + 1])
                    i++;
            }
        }
    }

    std::vector<std::vector<int>> permuteUnique(std::vector<int> &nums) {
        std::vector<std::vector<int>> result;
        std::vector<int> current;
        std::sort(nums.begin(), nums.end());
        std::vector<bool> used_indexes(nums.size());
        f(nums, current, result, used_indexes, nums.size());
        return result;
    }

}