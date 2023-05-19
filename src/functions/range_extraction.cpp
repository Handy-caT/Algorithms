//
// Created by Максим on 18.05.23.
//

#include "range_extraction.h"

std::string custom_functions::range_extraction(std::vector<int> args) {
    int i = 0;
    int last;
    bool range = false;
    bool ind = false;
    std::string result;

    last = args[0];
    i++;
    result += std::to_string(last);

    while(i < args.size()) {
        if(last + 1 == args[i]) {
            if(range) {
                ind = true;
            }
            range = true;
        } else {
            if(ind) {
                result += "-";
                result += std::to_string(last);
                range = false;
                ind = false;
            } else {
                if(range) {
                    result += ",";
                    result += std::to_string(last);
                    range = false;
                }
            }
            result += ",";
            result += std::to_string(args[i]);
        }
        last = args[i];
        i++;
    }

    if(ind) {
        result += "-";
        result += std::to_string(last);
    } else {
        if(range) {
            result += ",";
            result += std::to_string(last);
        }
    }

    return result;
}