#pragma once

#include <vector>

// https://leetcode.com/problems/search-a-2d-matrix/
namespace search_a_2d_matrix {

    namespace {

        int search(const std::vector<std::vector<int>> &matrix, int target, int start, int end, int columns) {
            const auto middle = (start + end) / 2;
            const std::pair<int, int> pos{int(middle / columns), middle % columns};

            if (middle == start) {
                return (matrix[pos.first][pos.second] == target) ? start : -1;
            }
            if (matrix[pos.first][pos.second] > target) {
                return search(matrix, target, start, middle, columns);
            } else {
                return search(matrix, target, middle, end, columns);
            }
        }

    }

    bool search(std::vector<std::vector<int>> &matrix, int target) {
        return search(matrix, target, 0, matrix.size() * matrix[0].size(), matrix[0].size()) != -1;
    }

}