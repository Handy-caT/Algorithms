//
// Created by Максим on 10.05.23.
//

#include "valid_braces.h"
#include <stack>
#include <map>

/**
 * Function that takes a string of braces, and determines if the order of the braces is valid.
 * It should return true if the string is valid, and false if it's invalid.
 *
 * @param std::string braces
 * @return bool
 */
bool custom_functions::valid_braces(std::string braces) {
    std::stack<char> stack;

    std::map<char, char> brace_pairs = {
            {'(', ')'},
            {'[', ']'},
            {'{', '}'}
    };

    for (auto &brace : braces) {
        if (brace == '(' || brace == '[' || brace == '{') {
            stack.push(brace);
        } else {
            if (stack.empty()) {
                return false;
            }
            if (brace_pairs[stack.top()] != brace) {
                return false;
            }
            stack.pop();
        }
    }

    return stack.empty();
}