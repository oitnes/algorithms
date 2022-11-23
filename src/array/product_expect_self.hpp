#pragma once

#include <vector>
#include <cassert>

// https://leetcode.com/explore/interview/card/top-interview-questions-hard/116/array-and-strings/827/
namespace product_expect_self {

    std::vector<int> calc(std::vector<int> &nums) {
        std::vector<int> answers(nums.size(), 0);

        int production = 1, zeros_number = 0;
        for (const auto &num: nums) {
            if (num == 0) {
                zeros_number++;
            } else {
                production *= num;
            }
        }
        assert(zeros_number >= 0);

        if (zeros_number == 0) {
            for (int i = 0; i < nums.size(); i++) answers[i] = production / nums[i];
        } else if (zeros_number == 1) {
            for (int i = 0; i < nums.size(); i++) answers[i] = (nums[i] != 0) ? 0 : production;
        }

        return answers;
    }

}