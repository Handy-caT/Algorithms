//
// Created by Максим on 11.05.23.
//
#include "rot13.h"

/**
 * Function that encodes the given string using ROT13 cipher
 * Cipher shifts each letter by 13 places
 *
 * @param string msg
 * @return string
 */
std::string custom_functions::rot13(std::string msg) {
    char lowercase_letters[] = "abcdefghijklmnopqrstuvwxyz";
    char uppercase_letters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    std::string result;

    for (char &i: msg) {
        if (!isalpha(i)) {
            result += i;
        } else {
            if (islower(i)) {
                result += lowercase_letters[(int) (i - 'a' + 13) % 26];
            } else {
                result += uppercase_letters[(int) (i - 'A' + 13) % 26];
            }
        }
    }

    return result;
}