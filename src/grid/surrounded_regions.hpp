#pragma once

#include <vector>

// https://leetcode.com/problems/surrounded-regions/
namespace surrounded_region {

    namespace {

        bool replace(std::vector<std::vector<char>> &grid, int x, int y,
                     char target, char symbol,
                     int prevX, int prevY,
                     int n, int m) {
            if (grid[x][y] == target) {
                grid[x][y] = symbol;
                bool flag = false;
                if (x + 1 < n && x + 1 != prevX)
                    flag = replace(grid, x + 1, y, target, symbol, x, y, n, m) || flag;
                if (x - 1 >= 0 && x - 1 != prevX)
                    flag = replace(grid, x - 1, y, target, symbol, x, y, n, m) || flag;
                if (y + 1 < m && y + 1 != prevY)
                    flag = replace(grid, x, y + 1, target, symbol, x, y, n, m) || flag;
                if (y - 1 >= 0 && y - 1 != prevY)
                    flag = replace(grid, x, y - 1, target, symbol, x, y, n, m) || flag;
                if (x == n - 1 || x == 0 || y == 0 || y == m - 1 || flag) {
                    return true;
                }
            }
            return false;
        }

    }

    void solve(std::vector<std::vector<char>> &board) {
        const char checked_symbol = '#';
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] == 'O') {
                    if (!replace(board, i, j, 'O', checked_symbol, -1, -1, board.size(), board[i].size())) {
                        replace(board, i, j, checked_symbol, 'X', -1, -1, board.size(), board[i].size());
                    }
                }
            }
        }
        for (auto &row: board) {
            for (auto &item: row) {
                if (item == checked_symbol)
                    item = 'O';
            }
        }
    }

}