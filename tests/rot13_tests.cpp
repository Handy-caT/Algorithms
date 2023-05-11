//
// Created by Максим on 11.05.23.
//

#include <rot13.h>
#include <gtest/gtest.h>

TEST(rot13, test) {
    std::map<std::string, std::string> test_cases = {
            {"test", "grfg"},
            {"Test", "Grfg"},
            {"AbCd", "NoPq"},
            {"",     ""}
    };

    for (auto &test_case : test_cases) {
        auto input = test_case.first;
        auto expected = test_case.second;
        auto result = custom_functions::rot13(input);

        ASSERT_EQ(expected, result);
    }
}