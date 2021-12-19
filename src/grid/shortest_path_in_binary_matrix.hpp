#pragma once

#include <vector>
#include <queue>

// https://leetcode.com/problems/shortest-path-in-binary-matrix/
namespace shortest_path_in_binary_matrix {
    int solve(std::vector<std::vector<int>> &grid) {
        const int N = grid.size();
        if (grid[0][0] == 1 || grid[N - 1][N - 1] != 0)
            return -1;
        std::vector<std::pair<int, int>> moves{{-1, -1},
                                               {-1, 0},
                                               {-1, 1},
                                               {0,  -1},
                                               {0,  1},
                                               {1,  -1},
                                               {1,  0},
                                               {1,  1}};
        std::queue<std::pair<int, int>> points;
        points.push({0, 0});

        for (int steps = 1; !points.empty(); steps++) {
            const int current_near_points = points.size();
            for (int i = 0; i < current_near_points; i++) {
                std::pair<int, int> current_point = points.front();
                points.pop();
                if (current_point.first == N - 1 && current_point.second == N - 1)
                    return steps;

                for (auto move: moves) {
                    int next_x = current_point.first + move.first;
                    int next_y = current_point.second + move.second;
                    if (next_x < 0 || next_y < 0 || next_x >= N || next_y >= N || grid[next_x][next_y] == 1)
                        continue;
                    grid[next_x][next_y] = 1;
                    points.push({next_x, next_y});
                }
            }
        }
        return -1;
    }
}