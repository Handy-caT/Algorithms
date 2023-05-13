//
// Created by Максим on 13.05.23.
//

#include <gtest/gtest.h>
#include <snail.h>

TEST(snail, test) {
    std::vector<std::vector<int>> v;
    std::vector<int> expected;

    v = {{}};
    expected = {};
    ASSERT_EQ(expected, custom_functions::snail(v));

    v = {{1}};
    expected = {1};
    ASSERT_EQ(expected, custom_functions::snail(v));

    v = {{1,2}, {4,3}};
    expected = {1,2,3,4};
    ASSERT_EQ(expected, custom_functions::snail(v));
}