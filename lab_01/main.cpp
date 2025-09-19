#include <iostream>
#include "include/lab.hpp"

int main() {
    std::string day;
    int num;
    std::cout << "Enter your day and number:\n";
    std::cin >> day;
    std::cin >> num;

    if (!IsCorrect(day)) {
        return 0;
    }
    
    if (AfraidNumber(day, num)) {
        std::cout << "I am so afraid!\n";
    } else {
       std::cout << "Fuuuh, I`m not scary :)\n";
    }

    return 0;
}