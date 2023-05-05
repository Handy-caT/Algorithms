//
// Created by Максим on 5.05.23.
//

#include <gtest/gtest.h>
#include <reverse_words.h>

TEST(reverse_words, test1) {
    std::map<std::string, std::string> test_cases = {
            {"Let's take LeetCode contest", "s'teL ekat edoCteeL tsetnoc"},
            {"God Ding",                    "doG gniD"}
    };

    for (auto &test_case: test_cases) {
        std::string input = test_case.first;
        std::string expected = test_case.second;
        std::string result = custom_functions::reverse_words(input);
        std::cout << "input: " << input << std::endl;
        std::cout << "expected: " << expected << std::endl;
        std::cout << "result: " << result << std::endl;
        std::cout << std::endl;
    }
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}