//
// Created by Максим on 5.05.23.
//
#include <gtest/gtest.h>
#include <highest_scoring_word.h>

TEST(highest_scoring_word, test) {
    std::map<std::string, std::string> test_cases = {
            {"man i need a taxi up to ubud", "taxi"},
            {"what time are we climbing up the volcano", "volcano"},
            {"take me to semynak", "semynak"},
            {"massage yes massage yes massage", "massage"},
            {"take two bintang and a dance please", "bintang"},
            {"aa b", "aa"},
    };

    for (auto &test_case : test_cases) {
        std::string input = test_case.first;
        std::string expected = test_case.second;
        std::string result = custom_functions::highestScoringWord(input);

        ASSERT_EQ(expected, result);
    }
}