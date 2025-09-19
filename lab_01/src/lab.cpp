#include "../include/lab.hpp"
#include <cmath>
#include <iostream>
#include <string>


bool AfraidNumber(const std::string& weekday,const int& number) {
    if (weekday == "Понедельник" && number == 12) return true;
    else if (weekday == "Вторник" && number > 95) return true;
    else if (weekday == "Среда" && number == 34) return true;
    else if (weekday == "Четверг" && number == 0) return true;
    else if (weekday == "Пятница" && number % 2 == 0) return true;
    else if (weekday == "Суббота" && number == 56) return true;
    else if (weekday == "Воскресенье" && std::abs(number) == 666 ) return true;

    return false;
}

bool IsCorrect(const std::string& str) {
    if ((str.size() / 2) < 5) {
        std::cout << "Your input not correct :(\n";
        return false;
    }
    
    for (const char& letter : str) {
        if ((letter & 0xFF) < 128) {
            std::cout << "Your input not correct :(\n";
            return false;
        }
    }
    
    return true;
}

