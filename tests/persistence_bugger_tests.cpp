//
// Created by Максим on 6.05.23.
//

#include <gtest/gtest.h>
#include <persistence_bugger.h>

TEST(persistence_bugger, test) {
    std::map<long long, int> test_cases = {
            {39, 3},
            {999, 4},
            {25, 2},
            {4, 0}
    };

    for (auto &test_case: test_cases) {
        auto input = test_case.first;
        auto expected = test_case.second;
        auto result = custom_functions::persistence_bugger(input);

        ASSERT_EQ(expected, result);
    }
}