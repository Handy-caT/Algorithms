//
// Created by Максим on 13.05.23.
//

#include "moving_zeros.h"

/**
 * Moves all zeroes to the end of the vector
 * and returns the result
 *
 * @param input
 * @return
 */
std::vector<int> custom_functions::move_zeroes(const std::vector<int> &input) {
    std::vector<int> result;
    int zeroes = 0;

    for (int i = 0; i < input.size(); i++) {
        if (input[i] == 0) {
            zeroes++;
        } else {
            result.push_back(input[i]);
        }
    }

    for (int i = 0; i < zeroes; i++) {
        result.push_back(0);
    }

    return result;
}
