//
// Created by Максим on 9.05.23.
//

#include <gtest/gtest.h>
#include <to_camel_case.h>

TEST(to_camel_case, test) {
    std::map<std::string, std::string> test_cases = {
            {"the-stealth-warrior", "theStealthWarrior"},
            {"The_Stealth_Warrior", "TheStealthWarrior"},
            {"",                    ""},
            {"A-B-C",               "ABC"}
    };

    for (auto &test_case: test_cases) {
        auto input = test_case.first;
        auto expected = test_case.second;
        auto result = custom_functions::to_camel_case(input);

        ASSERT_EQ(expected, result);
    }
}