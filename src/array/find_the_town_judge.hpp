#pragma once

#include <vector>

// https://leetcode.com/problems/find-the-town-judge/
namespace find_the_town_judge {

    int findJudge(int n, std::vector<std::vector<int>> &trust) {
        std::vector<int> trusts(n, 0);
        std::vector<bool> trusted(n, false);
        for (auto &sub: trust) {
            trusts[sub[1] - 1] += 1;
            trusted[sub[0] - 1] = true;
        }
        int judge = -1;
        for (int i = 0; i < n; i++) {
            if (trusts[i] == n - 1 && !trusted[i]) {
                if (judge == -1) {
                    judge = i + 1;
                } else {
                    return -1;
                }
            }
        }
        return judge;
    }

}