//
// Created by Максим on 4.05.23.
//
#import <cmath>
#include "find_next_square.h"


/**
 * Functions that finds next perfect square for the input square.
 * If the input square isn't perfect, returns -1
 *
 *
 * @param long sq - input square
 * @return long if exists, -1 if not
 */
long custom_functions::find_next_square(long sq) {
    long root = (long) sqrt(sq);

    if (root * root == sq) {
        return (root + 1) * (root + 1);
    } else {
        return -1;
    }
}
