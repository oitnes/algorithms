#pragma once

#include <vector>
#include <queue>

// https://leetcode.com/problems/all-paths-from-source-to-target/
namespace all_paths_from_source_to_target {

    std::vector<std::vector<int>> find(const std::vector<std::vector<int>> &graph) {
        const int N = graph.size();
        std::queue<std::pair<int, std::vector<int>>> targets;
        targets.push({0, std::vector<int>{0}});
        std::vector<std::vector<int>> result;
        while (!targets.empty()) {
            std::pair<int, std::vector<int>> current = targets.front();
            targets.pop();
            if (current.first == N - 1) {
                result.push_back(current.second);
            }
            auto &moves = graph[current.first];
            for (auto move: moves) {
                std::vector<int> next_path(current.second);
                next_path.push_back(move);
                targets.push({move, next_path});
            }
        }
        return result;
    }

}