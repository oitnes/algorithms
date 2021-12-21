#pragma once

#include <vector>

// https://leetcode.com/problems/combination-sum/
namespace combination_sum {

    namespace {

        void f(std::vector<int> &candidates, int target,
               std::vector<std::vector<int>> &result, std::vector<int> &ds, int current) {
            if (current == candidates.size()) {
                if (target == 0)
                    result.push_back(ds);
                return;
            }
            if (candidates[current] <= target) {
                ds.push_back(candidates[current]);
                f(candidates, target - candidates[current], result, ds, current);
                ds.pop_back();
            }
            f(candidates, target, result, ds, current + 1);
        }

    }

    std::vector<std::vector<int>> combinationSum(std::vector<int> &candidates, int target) {
        std::vector<std::vector<int>> result;
        std::vector<int> ds;
        f(candidates, target, result, ds, 0);
        return result;
    }

}