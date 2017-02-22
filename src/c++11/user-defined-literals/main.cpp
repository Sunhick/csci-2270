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
    
    
    return 0;
}
