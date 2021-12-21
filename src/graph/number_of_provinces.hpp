#pragma once

#include <vector>

// https://leetcode.com/problems/number-of-provinces/
namespace number_of_provinces {

    namespace {

        void connect(std::vector<std::vector<int>> &isConnected, std::vector<bool> &registry, int prev, int current) {
            if (prev == current)
                return;
            auto &city = isConnected[current];
            for (int i = 0; i < city.size(); i++) {
                if (city[i] == 1 && !registry[i]) {
                    registry[i] = true;
                    connect(isConnected, registry, current, i);
                }
            }
        }

    }

    int find(std::vector<std::vector<int>> &isConnected) {
        std::vector<bool> registry(isConnected.size());
        int counter = 0;
        for (int i = 0; i < isConnected.size(); i++) {
            if (!registry[i]) {
                registry[i] = true;
                counter++;
            }
            connect(isConnected, registry, -1, i);
        }
        return counter;
    }

}