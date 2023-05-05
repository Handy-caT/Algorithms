//
// Created by Максим on 4.05.23.
//
#import <cmath>
#include <iostream>
#include <map>

namespace custom_functions {
    long find_next_square(long sq) {
        long root = (long) sqrt(sq);

        if (root * root == sq) {
            return (root + 1) * (root + 1);
        } else {
            return -1;
        }
    }
}

namespace custom_functions_tests {
    void find_next_square_test() {
        std::map<long, long> test_cases = {
                {121, 144},
                {625, 676},
                {319225, 320356},
                {15241383936, 15241630849},
                {155, -1},
                {342786627, -1}
        };

        for (auto &test_case : test_cases) {
            long input = test_case.first;
            long expected = test_case.second;
            long result = custom_functions::find_next_square(input);
            std::cout << "input: " << input << std::endl;
            std::cout << "expected: " << expected << std::endl;
            std::cout << "result: " << result << std::endl;
            std::cout << std::endl;
        }
    }
}