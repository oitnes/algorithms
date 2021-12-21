#pragma once

#include <vector>
#include <string>

// https://leetcode.com/problems/word-search/
namespace word_search {

    namespace {

        bool check(std::vector<std::vector<char>> &board, std::string &word, int candidate, int i, int j) {
            if (candidate == word.size())
                return true;
            if (i < 0 || i > board.size() - 1 || j < 0 || j > board[0].size() - 1 || board[i][j] != word[candidate])
                return false;

            const char saved_char = board[i][j];
            board[i][j] = '#';
            bool found = check(board, word, candidate + 1, i + 1, j)
                         || check(board, word, candidate + 1, i, j + 1)
                         || check(board, word, candidate + 1, i - 1, j)
                         || check(board, word, candidate + 1, i, j - 1);
            board[i][j] = saved_char;
            return found;
        }

    }

    bool exist(std::vector<std::vector<char>> &board, std::string word) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == word[0] && check(board, word, 0, i, j)) {
                    return true;
                }
            }
        }
        return false;
    }

}