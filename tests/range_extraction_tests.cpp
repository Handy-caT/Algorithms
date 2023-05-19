//
// Created by Максим on 18.05.23.
//

#include <range_extraction.h>
#include <gtest/gtest.h>

TEST(range_extraction, test) {
    std::map<std::vector<int>, std::string> test_cases = {
            {{-6,-3,-2,-1,0,1,3,4,5,7,8,9,10,11,14,15,17,18,19,20}, "-6,-3-1,3-5,7-11,14,15,17-20"},
            {{-3,-2,-1,2,10,15,16,18,19,20}, "-3--1,2,10,15,16,18-20"}
    };

    for (auto &test_case: test_cases) {
        auto input = test_case.first;
        auto expected = test_case.second;
        auto result = custom_functions::range_extraction(input);

        ASSERT_EQ(expected, result);
    }
}
