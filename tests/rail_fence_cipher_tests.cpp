//
// Created by Максим on 28.05.23.
//

#include <gtest/gtest.h>
#include "rail_fence_cipher.h"
#include <functional>

TEST(rail_fence_cipher_encode, test) {
    std::map<std::pair<std::string, int>, std::string> test_cases = {
            {{"WEAREDISCOVEREDFLEEATONCE", 3}, "WECRLTEERDSOEEFEAOCAIVDEN"},
            {{"WEAREDISCOVEREDFLEEATONCE", 5}, "WCLEESOFECAIVDENRDEEAOERT"},
            {{"WEAREDISCOVEREDFLEEATONCE", 2}, "WAEICVRDLETNEERDSOEEFEAOC"},
            {{"_w%8$Icf5K3eGy,v\\a6PN5q28bx1x#SpIb", 6}, "_3NSwKeP5#p%5G6qxI8fya21b$c,\\8xIvb"},
            {{"Hello, World!", 3}, "Hoo!el,Wrdl l"},
            {{"Hello, World!", 4}, "H !e,Wdloollr"},
            {{"", 3}, ""}
    };

    for (auto &test_case: test_cases) {
        auto input = test_case.first;
        auto expected = test_case.second;
        auto result = custom_functions::encode_rail_fence_cipher(input.first, input.second);

        ASSERT_EQ(expected, result);
    }
}

TEST(rail_fence_cipher_decode, test) {
    std::map<std::pair<std::string, int>, std::string> test_cases = {
            {{"WECRLTEERDSOEEFEAOCAIVDEN", 3}, "WEAREDISCOVEREDFLEEATONCE"},
            {{"WCLEESOFECAIVDENRDEEAOERT", 5}, "WEAREDISCOVEREDFLEEATONCE"},
            {{"WAEICVRDLETNEERDSOEEFEAOC", 2}, "WEAREDISCOVEREDFLEEATONCE"},
            {{"_3NSwKeP5#p%5G6qxI8fya21b$c,\\8xIvb", 6}, "_w%8$Icf5K3eGy,v\\a6PN5q28bx1x#SpIb"},
            {{"Hoo!el,Wrdl l", 3}, "Hello, World!"},
            {{"H !e,Wdloollr", 4}, "Hello, World!"},
            {{"", 3}, ""}
    };

    for (auto &test_case: test_cases) {
        auto input = test_case.first;
        auto expected = test_case.second;
        auto result = custom_functions::decode_rail_fence_cipher(input.first, input.second);

        ASSERT_EQ(expected, result);
    }
}