//
// Created by Максим on 4.05.23.
//
#include <iostream>
#include <map>

namespace custom_functions {
    std::string highestScoringWord(const std::string &str)
    {
        std::string result;
        int max = 0;
        int score = 0;
        std::string word;

        for (auto &c : str) {
            if (c == ' ') {
                if (score > max) {
                    max = score;
                    result = word;
                }
                word = "";
                score = 0;
            } else {
                score += c - 'a' + 1;
                word += c;
            }
        }
        if (score > max) {
            result = word;
        }

        return result;
    }
}

namespace custom_functions_tests {
    void highestScoringWord_test() {
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
            std::cout << "input: " << input << std::endl;
            std::cout << "expected: " << expected << std::endl;
            std::cout << "result: " << result << std::endl;
            std::cout << std::endl;
        }
    }
}
