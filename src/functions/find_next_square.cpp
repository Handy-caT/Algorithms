//
// Created by Максим on 4.05.23.
//
#import <cmath>
#include <map>
#include "find_next_square.h"


long custom_functions::find_next_square(long sq) {
    long root = (long) sqrt(sq);

    if (root * root == sq) {
        return (root + 1) * (root + 1);
    } else {
        return -1;
    }
}
