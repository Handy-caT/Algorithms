//
// Created by Максим on 28.05.23.
//
#include "sum_intervals.h"

bool compare_pair(std::pair<int,int> first, std::pair<int,int> second) {
    return first.first < second.first;
}

/**
 * Function that sums all intervals
 *
 * @param intervals
 * @return int
 */
int custom_functions::sum_intervals(std::vector<std::pair<int, int>> intervals) {
    int result = 0;
    std::sort(intervals.begin(), intervals.end(), compare_pair);

    auto last = intervals[0].second;
    result += last - intervals[0].first;
    int i = 1;

    while(i < intervals.size()) {
        if (intervals[i].first <= last) {
            if (intervals[i].second > last) {
                result += intervals[i].second - last;
                last = intervals[i].second;
            }
        } else {
            result += intervals[i].second - intervals[i].first;
            last = intervals[i].second;
        }
        i++;
    }

    return result;
}