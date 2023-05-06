//
// Created by Максим on 4.05.23.
//
#include "solution.h"
#include "main.h"


void romanToInt::test() {
    Solution solution;

    std::map<std::string, int> test_cases = {
            {"III", 3},
            {"IV",  4},
            {"IX",  9},
            {"LVIII", 58},
            {"MCMXCIV", 1994}
    };

    for (auto &test_case : test_cases) {
        std::string input = test_case.first;
        int expected = test_case.second;
        int result = solution.romanToInt(input);
        std::cout << "input: " << input << std::endl;
        std::cout << "expected: " << expected << std::endl;
        std::cout << "result: " << result << std::endl;
        std::cout << std::endl;
    }

}

int main() {
    romanToInt::test();
    return 0;
}
