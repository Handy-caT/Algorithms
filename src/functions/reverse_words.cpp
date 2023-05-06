//
// Created by Максим on 4.05.23.
//

#include <map>
#include "reverse_words.h"


/**
 *  Function that reverses words in the given string
 *
 * @param string str
 * @return string
 */
std::string custom_functions::reverse_words(const std::string &str) {
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
