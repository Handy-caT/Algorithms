//
// Created by Максим on 6.05.23.
//

#include "persistence_bugger.h"

int multiply_digits(long long number) {
    int result = 1;

    while (number > 0) {
        result *= (int) (number % 10);
        number /= 10;
    }

    return result;
}


int custom_functions::persistence_bugger(long long number) {
    int count = 0;

    while (number >= 10) {
        number = multiply_digits(number);
        count++;
    }

    return count;
}