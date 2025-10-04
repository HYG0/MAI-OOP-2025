#include "../include/lab.hpp"
#include <cmath>
#include <exception>
#include <iostream>
#include <string>
#include <stdexcept>

bool AfraidNumber(const std::string& weekday,const int& number) {
    return (weekday == "Понедельник" && number == 12) || (weekday == "Вторник" && number > 95) ||
    (weekday == "Среда" && number == 34) || (weekday == "Четверг" && number == 0) || (weekday == "Пятница" && (number & 1) == 0) ||
    (weekday == "Суббота" && number == 56) || (weekday == "Воскресенье" && std::abs(number) == 666 );
}

bool IsCorrect(const std::string& str) {
    if ((str.size() / 2) < 5) {
        throw std::runtime_error("Weekday don't exist!");
        return false;
    }
    
    for (const char& letter : str) {
        if ((letter & 0xFF) < 128) {
            throw std::runtime_error("Weekday don't exist!");
            return false;
        }
    }
    
    return true;
}

