#pragma once

#include <vector>

// https://leetcode.com/problems/search-in-rotated-sorted-array/
namespace search_in_rotated_binary_array {

    namespace {

        int rotatedBinarySearch(std::vector<int> &nums, int target, int start, int end, int start_index) {
            const int search_middle = (start + end) / 2;
            const int real_middle = (search_middle < (nums.size() - start_index)) ? (search_middle + start_index) : (
                    search_middle + start_index - static_cast<int>(nums.size()));
            if (start != search_middle) {
                return (nums[real_middle] > target) ? rotatedBinarySearch(nums, target, start, search_middle,
                                                                          start_index)
                                                    : rotatedBinarySearch(nums, target, search_middle, end,
                                                                          start_index);
            } else {
                return (nums[real_middle] == target) ? real_middle : -1;
            }
        }

        int zeroIndexBinarySearch(std::vector<int> &nums, int previous, int start, int end) {
            const auto middle = (start + end) / 2;
            if (start != middle) {
                return (nums[middle] > previous) ? zeroIndexBinarySearch(nums, nums[middle], middle, end)
                                                 : zeroIndexBinarySearch(nums, nums[middle], start, middle);
            } else {
                return middle + 1;
            }
        }

    }

    int search(std::vector<int> &nums, int target) {
        auto start_index = zeroIndexBinarySearch(nums, nums[0], 0, nums.size());
        return rotatedBinarySearch(nums, target, 0, nums.size(), start_index);
    }

}