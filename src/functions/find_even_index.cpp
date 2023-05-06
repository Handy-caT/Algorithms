//
// Created by Максим on 6.05.23.
//

#include "find_even_index.h"


/**
 * Function that returns index of "middle" element in array.
 * "Middle" element is element, where all left elements sum is equal
 * to all right elements sum. If index is 0, there are no left elements,
 * but the left sum is 0
 *
 * @param numbers of size 0 < size < 1000
 * @return index if exists, -1 if not
 *
 */
int custom_functions::find_even_index(const std::vector<int> &numbers) {
    int sum = 0;

    for (auto &item : numbers) {
        sum += item;
    }

    int left_sum = 0;
    int right_sum = sum;
    int i = 0;

    right_sum -= numbers[i];
    i++;

    while (left_sum != right_sum && i < (int) numbers.size()) {
        left_sum += numbers[i-1];
        right_sum -= numbers[i];
        i++;
    }

    if (left_sum == right_sum) {
        return i - 1;
    } else {
        return -1;
    }
}