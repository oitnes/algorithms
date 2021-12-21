#pragma once

#include <vector>

// https://leetcode.com/problems/number-of-islands/
namespace number_of_islands {

    namespace {

        void remove(std::vector<std::vector<char>> &grid, int x, int y, int prevX, int prevY, int n, int m) noexcept {
            if (grid[x][y] != '0') {
                grid[x][y] = '0';
                if (x + 1 < n && x + 1 != prevX)
                    remove(grid, x + 1, y, x, y, n, m);
                if (x - 1 >= 0 && x - 1 != prevX)
                    remove(grid, x - 1, y, x, y, n, m);
                if (y + 1 < m && y + 1 != prevY)
                    remove(grid, x, y + 1, x, y, n, m);
                if (y - 1 >= 0 && y - 1 != prevY)
                    remove(grid, x, y - 1, x, y, n, m);
            }
        }

    }

    int calc(std::vector<std::vector<char>> &grid) {
        int counter = 0, n = grid.size(), m = grid[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1') {
                    counter++;
                    remove(grid, i, j, -1, -1, n, m);
                }
            }
        }
        return counter;
    }

}