#pragma once

#include <vector>

// https://leetcode.com/problems/find-peak-element/
namespace find_peak_element {

    namespace {

        int peakBinarySearch(const std::vector<int> &nums, int start, int end) noexcept {
            if (start < end) {
                int middle = (start + end) / 2;
                if (middle == 0) {
                    return (nums[middle] <= nums[middle + 1]) ? peakBinarySearch(nums, middle + 1, end) : middle;
                }
                if (middle == nums.size() - 1) {
                    return (nums[middle] <= nums[middle - 1]) ? peakBinarySearch(nums, start, middle - 1) : middle;
                }
                if (nums[middle] > nums[middle - 1] && nums[middle] > nums[middle + 1])
                    return middle;
                return (nums[middle - 1] < nums[middle + 1]) ? peakBinarySearch(nums, middle + 1, end)
                                                             : peakBinarySearch(nums, start, middle - 1);
            }
            return start;
        }
    }

    int findPeakElement(std::vector<int> &nums) {
        return peakBinarySearch(nums, 0, nums.size() - 1);
    }

}