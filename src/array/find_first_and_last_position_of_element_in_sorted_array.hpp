#pragma once

#include <vector>

// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
namespace find_first_and_last_position_of_element_in_sorted_array {

    namespace {

        int binarySearch(std::vector<int> &nums, int target, int start, int end) {
            const auto middle = (start + end) / 2;
            if (start != middle) {
                return (nums[middle] > target) ? binarySearch(nums, target, start, middle) : binarySearch(nums, target,
                                                                                                          middle, end);
            } else {
                return (!nums.empty()) && (nums[middle] == target) ? middle : -1;
            }
        }

    }

    std::pair<int, int> search(std::vector<int> &nums, int target) {
        auto start = binarySearch(nums, target, 0, nums.size());
        if (start != -1) {
            auto end = start;
            while ((end < (nums.size() - 1)) && (nums[start] == nums[end + 1])) {
                end++;
            }
            while ((0 < start) && (nums[end] == nums[start - 1])) {
                start--;
            }
            return {start, end};
        } else {
            return {-1, -1};
        }
    }

}