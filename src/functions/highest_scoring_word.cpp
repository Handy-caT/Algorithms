//
// Created by Максим on 4.05.23.
//
#include <iostream>
#include "highest_scoring_word.h"


/**
 * Function that finds highest scoring word in a string.
 * Score is sum of points that equals to letter position in the alphabet.
 *
 * @param string str
 * @return string
 */
std::string custom_functions::highestScoringWord(const std::string &str) {
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