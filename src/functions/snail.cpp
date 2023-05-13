//
// Created by Максим on 11.05.23.
//
#include "snail.h"

using VecInt = std::vector<int>;


/**
 * Function that snails through the given map
 * and returns the result as a vector
 *
 * @param snail_map
 * @return
 */
VecInt custom_functions::snail(const std::vector<VecInt> &snail_map) {
    int i = 0;
    int j = 0;
    int n = (int) snail_map.size();
    VecInt result;

    if (snail_map[0].empty()) {
        return result;
    }

    while (n > 0) {
        for (int k = 0; k < n; k++) {
            result.push_back(snail_map[i][j]);
            j++;
        }
        j--;
        i++;
        n--;
        for (int k = 0; k < n; k++) {
            result.push_back(snail_map[i][j]);
            i++;
        }
        i--;
        j--;
        for (int k = 0; k < n; k++) {
            result.push_back(snail_map[i][j]);
            j--;
        }
        j++;
        i--;
        n--;
        for (int k = 0; k < n; k++) {
            result.push_back(snail_map[i][j]);
            i--;
        }
        i++;
        j++;
    }

    return result;
}
