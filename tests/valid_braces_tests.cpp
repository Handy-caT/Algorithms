//
// Created by Максим on 10.05.23.
//

#include <valid_braces.h>
#include <gtest/gtest.h>

TEST(valid_braces, test1) {
    std::map<std::string, bool> test_cases = {
            {"{}", true},
            {"[(])", false},
            {"({})[({})]", true},
            {"())({}}{()][][", false},
            {"(({{[[]]}}))", true}
    };

    for (auto &test_case : test_cases) {
        auto input = test_case.first;
        auto expected = test_case.second;
        auto result = custom_functions::valid_braces(input);

        ASSERT_EQ(expected, result);
    }
}