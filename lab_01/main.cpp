#include <iostream>
#include "include/lab.hpp"

int main() {
    std::string day;
    std::cout << "Enter you day:\n";
    std::cin >> day;
    std::cout << AfraidNumber(&day) << "\n";
    std::cout << "Are you scared?" << "\n";
    return 0;
}