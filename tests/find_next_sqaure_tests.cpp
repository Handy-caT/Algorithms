//
// Created by Максим on 5.05.23.
//

#include <gtest/gtest.h>
#include <find_next_square.h>

TEST(find_next_square, test) {
    std::map<long, long> test_cases = {
            {121, 144},
            {625, 676},
            {319225, 320356},
            {15241383936, 15241630849},
            {155, -1},
            {342786627, -1}
    };

    for (auto &test_case : test_cases) {
        auto input = test_case.first;
        auto expected = test_case.second;
        auto result = custom_functions::find_next_square(input);

        ASSERT_EQ(expected, result);
    }
}