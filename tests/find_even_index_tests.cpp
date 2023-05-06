//
// Created by Максим on 6.05.23.
//

#include<find_even_index.h>
#include <gtest/gtest.h>

TEST(find_even_index, test) {
    std::map<std::vector<int>, int> test_cases = {
            {std::vector <int> { 1,2,3,4,3,2,1 }, 3},
            {std::vector <int> { 1,100,50,-51,1,1 }, 1},
            {std::vector <int> { 20,10,30,10,10,15,35 }, 3},
            {std::vector <int> { -1,-2,-3,-4,-3,-2,-1 }, 3},
            {std::vector <int> { 10,-80,10,10,15,35,20 }, 6},
            {std::vector <int> { 20,10,-80,10,10,15,35 }, 0},
            {std::vector <int> { 1,2,3,4,5,6 }, -1}
    };

    for (auto &test_case : test_cases) {
        auto input = test_case.first;
        auto expected = test_case.second;
        auto result = custom_functions::find_even_index(input);

        ASSERT_EQ(expected, result);
    }
}
