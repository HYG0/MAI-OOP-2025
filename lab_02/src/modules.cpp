#include "../include/modules.hpp"
#include <cctype>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <exception>
#include <stdexcept>
#include <sys/types.h>
#include <cmath>


Four::Four() : dex(0), fourth_vec(0) {
    std::cout << "Construction default\n";
}

Four::Four(const std::string& s) : dex(0), fourth_vec(s.size()) {
    // Заполняем начиная с конца
    for (size_t i = 0; i < fourth_vec.size(); ++i) {
        fourth_vec[i] = s[fourth_vec.size() - (i + 1)];
    }

    DeleteZero(fourth_vec);
    Validation();
    dex = DexRepresent(fourth_vec);
    std::cout << "Dex represent: " << dex << "\n";
}

Four::Four(const Four& other) : dex(other.dex),
                                fourth_vec(other.fourth_vec) {
    std::cout << "Copy construct\n";
}

Four::Four(const std::initializer_list<u_char> &lst) {
    std::cout << "here!\n";
    fourth_vec.resize(lst.size());
    // Заменить на iterators
    for (int i = 0; i < lst.size(); ++i) {
        fourth_vec[lst.size() - (i + 1)] = *(lst.begin() + i);
    }
    // fourth_vec.resize(lst.size());
    // std::copy(lst.begin(), lst.end(), std::inserter(fourth_vec, fourth_vec.begin()));

    DeleteZero(fourth_vec);
    Validation();
    dex = DexRepresent(fourth_vec);
    std::cout << "initializer list. Dex: " << dex << "\n";
}

// Удаляем ведущие нули
std::vector<u_char>& Four::DeleteZero(std::vector<u_char>& v) {
    while (*(v.end() - 1) == '0') {
            v.pop_back();
    }
    
    return v;
}

// Private metod for translate 4 to 10 SS
u_int32_t Four::DexRepresent(const std::vector<u_char>& v) {
    u_int32_t dex = 0;
    int8_t temp = 0;
    for (int i = v.size() - 1; i >= 0; --i) {
        temp = (static_cast<int>(v[i])) - 48;
        dex += temp * pow(4, i);
    }
    return dex;
}

void Four::DexToFourth(u_int32_t dex, std::vector<u_char>& v) {
    v.reserve(1);
    while (dex > 0) {
        v.push_back((dex % 4) + 48);
        dex /= 4;
    }

}

Four Four::Add(Four& num) {
    Four res = Four();

    res.dex = this->dex + num.dex;
    DexToFourth(res.dex, res.fourth_vec);

    res.Print();
    return res;
}

Four Four::Substract(Four& num) {
    Four res = Four();

    // Проверяем, что первое число больше другого
    if (dex < num.dex) {
        throw std::invalid_argument("First number > then second");
    }
    res.dex = this->dex - num.dex;
    DexToFourth(res.dex, res.fourth_vec);

    res.Print();
    return res;
}

Four Four::Copy(Four& other) {
    Four res = Four();
    res.dex = other.dex;
    res.fourth_vec = other.fourth_vec;
    
    return res;
}

bool Four::Equal(Four& num) {
    if (dex == num.dex) {
        return true;
    }

    return false;
}

bool Four::More(Four& num) {
    if (dex > num.dex) {
        return true;
    }

    return false;
}

bool Four::Less(Four& num) {
    if (dex < num.dex) {
        return true;
    }

    return false;
}

void Four::Print() {
    for (size_t i = 0; i < fourth_vec.size(); ++i) {
        std::cout << fourth_vec[fourth_vec.size() - (i + 1)];
    }
    std::cout << "\n";
}

void Four::Validation() {
    try {
        for (size_t i = 0; i < fourth_vec.size(); ++i) {
            if (!isdigit(fourth_vec[i]) || fourth_vec[i] > '3') {
                throw std::invalid_argument("The number should contain integer 0-3");
            }
        }
    } catch (std::invalid_argument& error_message) {
        std::cout << error_message.what() << "\n";
        this->~Four();
        std::exit(EXIT_FAILURE);
    }
}

Four::~Four() {
    if (!fourth_vec.empty()) {
        fourth_vec.clear();
    }
    std::cout << "Destruction object\n";
}