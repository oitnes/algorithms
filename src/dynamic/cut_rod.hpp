#pragma once

#include <vector>
#include <limits>

namespace cut_rod {

    int solveFull(const std::vector<int> &prices, int n) {
        if (n == 0)
            return 0;
        int q = std::numeric_limits<int>::min();
        for (int i = 0; i < n; i++) {
            q = std::max(q, prices[i] + solveFull(prices, n - i - 1));
        }
        return q;
    }

    namespace {

        int solveDynamicFn(const std::vector<int> &prices, std::vector<int> &mem, int n) {
            if (mem[n] != std::numeric_limits<int>::min())
                return mem[n];
            int q = (n == 0) ? 0 : std::numeric_limits<int>::min();
            for (int i = 0; i < n; i++) {
                q = std::max(q, prices[i] + solveDynamicFn(prices, mem, n - i - 1));
            }
            mem[n] = q;
            return q;
        }

    }

    int solveDynamic(const std::vector<int> &prices, int n) {
        std::vector<int> mem(n + 1, std::numeric_limits<int>::min());
        return solveDynamicFn(prices, mem, n);
    }
}