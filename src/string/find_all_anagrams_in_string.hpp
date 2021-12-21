#pragma once

#include <vector>
#include <string>

// https://leetcode.com/problems/find-all-anagrams-in-a-string/
namespace find_all_anagrams_in_string {

    namespace {

        bool isEqual(const std::vector<int> &a, const std::vector<int> &b) noexcept {
            for (int i = 0; i < a.size(); i++) {
                if (a[i] != b[i])
                    return false;
            }
            return true;
        }

        inline int toIndex(char ch) noexcept {
            return static_cast<int>(ch) - static_cast<int>('a');
        }

    }

    std::vector<int> find(std::string s, std::string p) {
        std::vector<int> target_counter(26);
        for (auto ch: p) {
            target_counter[toIndex(ch)] += 1;
        }
        std::vector<int> current_counter(26);
        std::vector<int> result;
        for (int index = 0, symbols_counter = 0; index < s.size(); index++) {
            auto income = toIndex(s[index]);
            current_counter[income] += 1;
            if (target_counter[income] > 0)
                symbols_counter++;
            if (index >= p.size()) {
                auto outcome = toIndex(s[index - p.size()]);
                current_counter[outcome] -= 1;
                if (target_counter[outcome] > 0)
                    symbols_counter--;
            }

            if (symbols_counter == p.size()) {
                if (isEqual(current_counter, target_counter)) {
                    result.push_back(index - p.size() + 1);
                }
            }
        }
        return result;
    }
}