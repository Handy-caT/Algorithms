#include "solution.h"

#include <map>

int romanToInt::Solution::romanToInt(const std::string s) {
    std::map<char, int> roman_map;
    roman_map['I'] = 1;
    roman_map['V'] = 5;
    roman_map['X'] = 10;
    roman_map['L'] = 50;
    roman_map['C'] = 100;
    roman_map['D'] = 500;
    roman_map['M'] = 1000;

    int length = (int) s.size();
    int result = 0;
    int current;

    for (int i = length; i >= 0; i--) {
        current = roman_map[s[i]];
        if (current < result && i < length && s[i + 1] != s[i]) {
            result -= current;
        } else {
            result += current;
        }
    }

    return result;
}