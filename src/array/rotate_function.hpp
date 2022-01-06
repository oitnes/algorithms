#pragma once

#include <vector>
#include <cmath>

// https://leetcode.com/problems/rotate-function
namespace rotate_function {

    int maxRotateFunction(std::vector<int> &nums) {
        int numbers_sum = 0, result = 0;
        for (int i = 0; i < nums.size(); i++) {
            numbers_sum += nums[i];
            result += (i * nums[i]);
        }
        for (int i = nums.size() - 1, curSum = result; i > 0; i--) {
            curSum = curSum + (numbers_sum - nums[i]) - (nums[i] * (nums.size() - 1));
            result = std::max(result, curSum);
        }
        return result;
    }

}