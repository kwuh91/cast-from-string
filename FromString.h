#ifndef CAST_FROM_STRING_FROMSTRING_H
#define CAST_FROM_STRING_FROMSTRING_H

#include "CastException.h"
#include <iostream>
#include <algorithm>
#include <cmath>
#include <type_traits>
#include <bits/stdc++.h>

int conversion(std::string str) {
    int newNumber = 0;
    for (int i = (int) str.size() - 1; i >= 0; i--) {
        int power = (int) str.length() - i - 1;
        newNumber += (int) (std::pow(10.0, power) * (str[i] - '0'));
    }
    return newNumber;
}

bool consists_of_numbers(const std::string &str) {
    for (char c{' '}; c <= '/'; c++) {
        if (str.find(c) <= str.size() && c != '-' && c != '+') {
            return false;
        }
    }
    for (char c{':'}; c <= '~'; c++) {
        if (str.find(c) <= str.size()) {
            return false;
        }
    }
    return true;
}

template<typename T>
inline T FromString(const std::string &str) {
    if (std::is_same<T, bool>::value) {
        std::string case_bool_str = str;
        std::transform(case_bool_str.begin(), case_bool_str.end(), case_bool_str.begin(),
                       [](unsigned char c) { return std::tolower(c); });
        if (case_bool_str == "true" || case_bool_str == "false") {
            return case_bool_str[0] == 't';
        } else {
            if (case_bool_str.find(' ') <= str.size()) {
                throw CastException("There is a blank space");
            }
            throw CastException("Invalid input");
        }
    } else if (std::is_same<T, int>::value) {
        if (!consists_of_numbers(str)) {
            if (str.find(' ') <= str.size()) {
                throw CastException("There is a blank space");
            }
            throw CastException("Not a number");
        }
        switch (str[0]) {
            case '-': {
                char c{'8'};
                std::string neg_numb = str.substr(1);
                if (neg_numb.size() > 10) {
                    throw CastException("Number too small");
                } else if (neg_numb.size() == 10 && neg_numb[neg_numb.size() - 1] > c) {
                    throw CastException("Number too small");
                }

                return conversion(neg_numb) * -1;
            }
            default: {
                std::string pos_numb = str;
                char c{'7'};
                if (str[0] == '+') {
                    pos_numb = str.substr(1);
                }
                if (pos_numb.size() > 10) {
                    throw CastException("Number too big");
                } else if (pos_numb.size() == 10 && pos_numb[pos_numb.size() - 1] > c) {
                    throw CastException("Number too big");
                }
                return conversion(pos_numb);
            }
        }
    }
}

#endif //CAST_FROM_STRING_FROMSTRING_H
