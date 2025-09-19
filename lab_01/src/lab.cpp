#include "../include/lab.hpp"
#include <cmath>
#include <unicode/unistr.h>
#include <unicode/ustream.h>
#include <iostream>
#include <locale>
#include <string>

/*
 * Функция принимает строковое значение дня недели от пользователя.
 * К длине строки этого дня прибавляется порядковый номер дня
 * недели, т.е. Monday + 1, Tuesday + 2, ...
 * Возвращает функция целочисленный тип.
*/

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



// int AfraidNumber(std::string& weekday) {
//     std::setlocale(LC_ALL, "en_US.UTF-8");

//     std::string ru_alphabet = "абвгдеёжзийклмнопрстуфхцчшщъыьэюя";
    
//     // Получаем последний символ
//     std::string last_letter_str = weekday.substr(weekday.size() - 2, 2);
    
//     size_t pos = ru_alphabet.find(last_letter_str);

//     int first_byte = (last_letter_str[0] & 0xFF);
//     int second_byte = (last_letter_str[1] & 0xFF);

//     if (first_byte == 208 && ((143 < second_byte && second_byte < 176) || second_byte == 129)) {
//         std::cout << "This is Upper!!!" << second_byte <<  " \n";
//         if (144 <= second_byte && second_byte <= 159) {
//             last_letter_str[1] += 0x20;
//             std::cout << "HERE!\n";
//             std::cout << last_letter_str[1];
//         }
//     }
    
//     size_t letter_index = (pos / 2) + 1;  // т.к. каждый символ = 2 байта

//     std::cout << "Порядковый номер буквы '" << last_letter_str << "' в алфавите - " << letter_index << "\n";
    
//     return letter_index;
// }

// std::string string_to_lower(const std::string &inpt_string) {
//     icu::UnicodeString str = icu::UnicodeString::fromUTF8(inpt_string);
//     str.toLower();
//     std::string out_string;
//     str.toUTF8String(out_string);

//     return out_string;
// }