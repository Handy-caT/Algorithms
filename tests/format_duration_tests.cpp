//
// Created by Максим on 14.05.23.
//

#include <gtest/gtest.h>
#include <format_duration.h>

TEST(format_duration, test) {
    std::map<int, std::string> test_cases = {
            {0, "now"},
            {1, "1 second"},
            {62, "1 minute and 2 seconds"},
            {120, "2 minutes"},
            {3662, "1 hour, 1 minute and 2 seconds"},
            {15731080, "182 days, 1 hour, 44 minutes and 40 seconds"},
            {132030240, "4 years, 68 days, 3 hours and 4 minutes"}
    };

    for (auto &test_case : test_cases) {
        auto input = test_case.first;
        auto expected = test_case.second;
        auto result = custom_functions::format_duration(input);

        ASSERT_EQ(expected, result);
    }
}