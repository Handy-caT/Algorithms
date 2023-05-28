//
// Created by Максим on 28.05.23.
//

#include <gtest/gtest.h>
#include "sum_intervals.h"


TEST(sum_intervals, test) {
    std::map<std::vector<std::pair<int, int>>, int> test_cases = {
            {{{1, 5}, {6, 10}}, 8},
            {{{1, 4}, {7, 10}, {3, 5}}, 7}
    };

    for (auto &test_case: test_cases) {
        auto input = test_case.first;
        auto expected = test_case.second;
        auto result = custom_functions::sum_intervals(input);

        ASSERT_EQ(expected, result);
    }
}