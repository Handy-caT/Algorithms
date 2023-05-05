//
// Created by Максим on 4.05.23.
//
#include <iostream>
#include <map>

namespace custom_functions {
    std::string reverse_words(const std::string &str) {
        std::string result;
        std::string word;

        int length = (int) str.size();
        int i = 0;

        while (i < length) {
            if (str[i] != ' ') {
                word += str[i];
            } else {
                std::reverse(word.begin(), word.end());
                result += word + ' ';
                word = "";
            }

            i++;
        }
        std::reverse(word.begin(), word.end());
        result += word;

        return result;
    }
}

namespace custom_functions_tests {
    void reverse_words_test() {
        std::map<std::string, std::string> test_cases = {
                {"Let's take LeetCode contest", "s'teL ekat edoCteeL tsetnoc"},
                {"God Ding", "doG gniD"}
        };

        for (auto &test_case : test_cases) {
            std::string input = test_case.first;
            std::string expected = test_case.second;
            std::string result = custom_functions::reverse_words(input);
            std::cout << "input: " << input << std::endl;
            std::cout << "expected: " << expected << std::endl;
            std::cout << "result: " << result << std::endl;
            std::cout << std::endl;
        }
    }
}