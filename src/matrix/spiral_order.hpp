#pragma once

#include <vector>

// https://leetcode.com/explore/interview/card/top-interview-questions-hard/116/array-and-strings/828/
namespace spiral_order {

    std::vector<int> spiralOrder(std::vector<std::vector<int>> &matrix) {
        const int M = matrix.size(), N = matrix[0].size();
        std::vector<int> result(M * N, 0);

        std::vector<std::pair<int, int>> moves = {{0,  1},
                                                  {1,  0},
                                                  {0,  -1},
                                                  {-1, 0}};

        for (int i = 0, j = -1, k = 0, n = N, m = M - 1, switch_flag = 0, move_id = 0;
             k < M * N; move_id = (move_id + 1 < moves.size()) ? move_id + 1 : 0) {
            for (int counter = 0, counter_end = ((switch_flag++ % 2) ? m-- : n--); counter < counter_end; counter++) {
                i += moves[move_id].first;
                j += moves[move_id].second;
                result[k++] = matrix[i][j];
            }
        }

        return result;
    }

}