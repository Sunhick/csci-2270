//
//  main.cpp
//  literals
//
//  Created by Sunil on 2/21/17.
//  Copyright © 2017 Sunil. All rights reserved.
//

#include <iostream>
#include <string>

#include "Length.hpp"

using namespace std;

using LengthDouble = Length<double>;

// Ref: http://stackoverflow.com/questions/16596864/c11-operator-with-double-parameter
// The declaration of a literal operator shall have a parameter-declaration-clause e
// quivalent to one of the following:
//
// const char*
// unsigned long long int
// long double
// char
// wchar_t
// char16_t
// char32_t
// const char*, std::size_t
// const wchar_t*, std::size_t
// const char16_t*, std::size_t
// const char32_t*, std::size_t

LengthDouble operator"" _km(long double value) {
    return LengthDouble(value, Distance::Kilometers);
}

LengthDouble operator"" _mi(long double value) {
    return LengthDouble(value, Distance::Miles);
}

unsigned long long int operator"" _b(const char* bits) {
    unsigned acc = 0;
    while(*bits) {
        if (*bits == '1' || *bits == '0') {
            acc  = (acc << 1) + (*bits-'0');
        } else {
            throw std::runtime_error("Invalid binary digits!");
        }
        bits++;
    }
    return acc;
}

void increment(int& x) {
    ++x;
}

template<typename T>
function<void(void)> callback(std::function<void(T&)> f, T&& val) {
    auto k = [&]() {
        f(val);
    };
    return k;
}

int main(int argc, const char * argv[]) {
    auto a = Length<int>(30);
    auto b = Length<int>(10);
    Length<int> total = a + b;
    cout << total.getMiles() << endl;
    
    // why can't i perform direct + operator
    // auto t1 = 12.12_km + 23.23_mi;
    // Because of missing operator+ with move semantics.

    auto k = 12.12_km;
    auto l = 23.23_mi;
    auto t1 = k + l;
    cout << t1.getMiles() << endl;
    
    auto t2 = 12.12_km + 23.23_mi;
    cout << Length<>(23.23).getMiles() << endl;
    
    std::cout << "Another example of user defined literal" << endl;
    {
        auto acc = 1111_b;
        // auto acc2 = 1411_b;  // runtime error
        cout << acc << endl;
    }
    
    std::cout << "std::ref usage" << endl;
    {
        int val = 34;
        int& rval = std::ref(val);
        rval = 45;
        cout << rval << " " << val << endl;
        
        int i = 9;
        auto f = std::bind(increment, std::ref(i));
        f();
        auto invoke = callback<int&>(increment, i);
        invoke();
        
        cout << i << endl;
    }
    
    return 0;
}
