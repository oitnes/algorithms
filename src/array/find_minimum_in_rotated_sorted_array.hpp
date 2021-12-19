#pragma once

#include <vector>

// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
namespace find_minimum_in_rotated_sorted_array {

    namespace {

        int maxBinarySearch(std::vector<int> &nums, int previous, int start, int end) {
            auto middle = (start + end) / 2;
            if (start != middle) {
                return (nums[middle] > previous) ? maxBinarySearch(nums, nums[middle], middle, end) : maxBinarySearch(
                        nums, nums[middle], start, middle);
            }
            return middle;
        }
    }

    int find(std::vector<int> &nums) {
        auto r = maxBinarySearch(nums, nums[0], 0, nums.size()) + 1;
        return nums[(r < nums.size()) ? r : r - nums.size()];
    }

}