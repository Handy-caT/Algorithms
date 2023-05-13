//
// Created by Максим on 13.05.23.
//

#include <gtest/gtest.h>
#include <moving_zeros.h>

TEST(moving_zeros, test) {
    std::map<std::vector<int>, std::vector<int>> test_cases = {
            {{1, 2, 0, 1, 0, 1, 0, 3, 0, 1}, {1, 2, 1, 1, 3, 1, 0, 0, 0, 0}},
            {{0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0}},
            {{1, 2, 5, 1, 5, 1, 5, 3, 2, 1}, {1, 2, 5, 1, 5, 1, 5, 3, 2, 1}}
    };

    for (auto& test_case : test_cases) {
        ASSERT_EQ(test_case.second, custom_functions::move_zeroes(test_case.first));
    }
}