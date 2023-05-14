//
// Created by Максим on 14.05.23.
//

#include "format_duration.h"

std::string DELIMITER = ", ";
std::string AND = " and ";
std::string NOW = "now";

std::vector<std::string> DURATION_NAMES{"second", "minute", "hour", "day", "year"};
std::vector<unsigned short> DURATIONS{365, 24, 60, 60};

std::string custom_functions::format_duration(int seconds) {
    std::vector<unsigned int> durations;
    unsigned int current;
    int i = DURATIONS.size() - 1;
    std::vector<std::string> parts;
    std::string result;

    if(seconds == 0) {
        return NOW;
    }

    while(seconds != 0 && i >= 0) {
        current = seconds % DURATIONS[i];
        durations.push_back(current);
        seconds = seconds / DURATIONS[i];
        i--;
    }

    if(seconds != 0) {
        durations.push_back(seconds);
    }

    i = 0;
    while(i < durations.size()) {
        current = durations[i];
        if(current != 0) {
            if(current > 1) {
                parts.push_back(std::to_string(current) + " " + DURATION_NAMES[i] + "s");
            } else {
                parts.push_back(std::to_string(current) + " " + DURATION_NAMES[i]);
            }
        }

        i++;
    }

    std::string temp;

    if(parts.size() > 1) {
        i = 0;
        temp += parts[i+1];
        temp += AND;
        temp += parts[i];

        result += temp;
        i += 2;

        while(i < parts.size()) {
            temp = parts[i];
            temp += DELIMITER;
            temp += result;
            result = temp;
            i++;
        }

        return result;
    } else {
        return parts[0];
    }
}