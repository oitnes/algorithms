#pragma once

#include <cmath>

// https://leetcode.com/problems/complement-of-base-10-integer/
namespace complement_of_base_ten {

    int bitwiseComplement(int n) {
        if (!n) return 1;
        int res = 0, i = 0, mask = 1;
        while (mask < n) {
            if (!(mask & n)) res += mask;
            mask = static_cast<int>(pow(2, ++i));
        }
        return res;
    }

}