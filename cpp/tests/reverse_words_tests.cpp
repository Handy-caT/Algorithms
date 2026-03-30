//
// Created by Максим on 5.05.23.
//

#include <gtest/gtest.h>
#include <reverse_words.h>

TEST(reverse_words, test) {
    std::map<std::string, std::string> test_cases = {
            {"Let's take LeetCode contest", "s'teL ekat edoCteeL tsetnoc"},
            {"God Ding",                    "doG gniD"}
    };

    for (auto &test_case: test_cases) {
        std::string input = test_case.first;
        std::string expected = test_case.second;
        std::string result = custom_functions::reverse_words(input);

        ASSERT_EQ(expected, result);
    }
}
