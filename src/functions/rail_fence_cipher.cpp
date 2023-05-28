//
// Created by Максим on 28.05.23.
//

#include "rail_fence_cipher.h"
#include <vector>

std::string custom_functions::encode_rail_fence_cipher(const std::string &str, int n) {
    std::string result;
    std::vector<std::string> rails(n);
    int i = 0;
    int j = 0;
    bool is_up = true;

    while (i < str.size()) {
        rails[j] += str[i];
        if (is_up) {
            j++;
            if (j == n) {
                is_up = false;
                j -= 2;
            }
        } else {
            j--;
            if (j == -1) {
                is_up = true;
                j += 2;
            }
        }
        i++;
    }

    for (auto &rail: rails) {
        result += rail;
    }

    return result;
}

std::string custom_functions::decode_rail_fence_cipher(const std::string &str, int n) {
    std::string result = std::string (str.size(), ' ');
    std::vector<std::string> rails(n);
    int i = 0;
    int j = 0;
    int k = 0;
    auto lines = std::vector<int>(n);

    while (j < str.size()) {
        result[j] = str[i];
        i++;
        j+=2*n-2;
    }
    k++;

    while (k < n-1) {
        j = k;
        while (j < str.size()) {
            result[j] = str[i];
            i++;
            j+=2*n-2-2*k;
            if (j < str.size()) {
                result[j] = str[i];
                i++;
                j+=2*k;
            }
        }
        k++;
    }

    j = k;
    while (j < str.size()) {
        result[j] = str[i];
        i++;
        j+=2*n-2;
    }

    return result;
}