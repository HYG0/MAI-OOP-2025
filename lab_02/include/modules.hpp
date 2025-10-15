#pragma once
#include <cstddef>
#include <iostream>
#include <string>
#include <sys/types.h>
#include <cstring>
#include <vector>


class Four {
private:
    u_int32_t dex;
    std::vector<u_char> fourth_vec;
    
public:
    Four();

    ~Four();

    Four(const Four& other);

    Four(const std::initializer_list<u_char> &lst);

    Four(const std::string &s);

    // Four(const char* s);

    // operator std::string();
    // explicit operator const char*();

    // Four(const std::initializer_list<u_char> &t);

    // Four& operator=(const Four& s); 

    Four Add(Four& num);

    Four Substract(Four& num);

    Four Copy(Four& num);

    bool Equal(Four& num);

    bool More(Four& num);

    bool Less(Four& num);

    void Print();


private:
    void Validation();

    u_int32_t DexRepresent(const std::vector<u_char>& v);

    std::vector<u_char>& DeleteZero(std::vector<u_char>& v);

    void DexToFourth(u_int32_t dex, std::vector<u_char>& v);
};