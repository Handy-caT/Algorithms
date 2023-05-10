//
// Created by Максим on 9.05.23.
//

#include "to_camel_case.h"

/**
 * Function that converts string to camel case
 *
 * @param std::string text - input string
 * @return std::string - camel case string
 */
std::string custom_functions::to_camel_case(std::string text) {
    std::string result;
    bool is_upper = false;

    for (auto &c: text) {
        if (c == '-' || c == '_') {
            is_upper = true;
        } else {
            if (is_upper) {
                result += (char) toupper(c);
                is_upper = false;
            } else {
                result += c;
            }
        }
    }

    return result;
}