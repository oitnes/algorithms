#pragma once

#include <string>
#include <vector>

// https://leetcode.com/problems/letter-combinations-of-a-phone-number/
namespace letter_combination_in_phone_number {

    namespace {

        void f(std::vector<std::string> &result, const std::vector<std::vector<char>> &numbers_letters,
               std::string current) {
            if (current.size() == numbers_letters.size()) {
                if (current.size() != 0)
                    result.push_back(current);
                return;
            }
            for (auto ch: numbers_letters[current.size()]) {
                f(result, numbers_letters, current + ch);
            }
        }

        std::vector<char> getLetters(int number) {
            switch (number) {
                case 2:
                    return {'a', 'b', 'c'};
                case 3:
                    return {'d', 'e', 'f'};
                case 4:
                    return {'g', 'h', 'i'};
                case 5:
                    return {'j', 'k', 'l'};
                case 6:
                    return {'m', 'n', 'o'};
                case 7:
                    return {'p', 'q', 'r', 's'};
                case 8:
                    return {'t', 'u', 'v'};
                case 9:
                    return {'w', 'x', 'y', 'z'};
                default:
                    return {};
            }
        }

    }

    std::vector<std::string> combine(std::string digits) {
        std::vector<std::vector<char>> numbers_letters;
        for (auto ch: digits) {
            numbers_letters.emplace_back(getLetters(static_cast<int>(ch) - static_cast<int>('0')));
        }
        std::vector<std::string> result;
        f(result, numbers_letters, std::string());
        return result;
    }
}