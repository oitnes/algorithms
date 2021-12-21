#pragma once

#include <vector>
#include <string>

// https://leetcode.com/problems/generate-parentheses/submissions/
namespace generate_parentheses {
    namespace {
        void f(std::vector<std::string> &result, std::string current, int current_opened, int all_opened, int n) {
            if (current.size() == n * 2) {
                result.push_back(current);
                return;
            }
            if (current_opened) {
                if (all_opened < n)
                    f(result, current + '(', current_opened + 1, all_opened + 1, n);
                f(result, current + ')', current_opened - 1, all_opened, n);
            } else {
                f(result, current + '(', 1, all_opened + 1, n);
            }
        }
    }

    std::vector<std::string> generate(int n) {
        std::vector<std::string> result;
        f(result, std::string(), 0, 0, n);
        return result;
    }
}