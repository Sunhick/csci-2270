//
//  main.cpp
//  Move
//
//  Created by Sunil on 2/20/17.
//  Copyright © 2017 Sunil. All rights reserved.
//

#include <iostream>
#include <cassert>

#include "Widget.h"

using namespace std;

void print(int&& r) {
    cout << r << endl;
}

void process(Widget& w) {
    cout << "widget& called" << endl;
}

void process(Widget&& w) {
    cout << "widget&& called" << endl;
}

template<typename T>
void logAndProcess(T&& w) {
    cout <<"log and process" << endl;
    process(std::forward<T>(w));
}

template<class T>
struct is_lvalue {
    const static bool value = false;
};

template<class T>
struct is_lvalue<T&&> {
    const static bool value = true;
};

int main(int argc, const char * argv[]) {
    // const vs contexpr:
    // const maybe a compile time or run time const.
    // where as constexpr is a compile time const
    const float pi = 3.14159;
    constexpr float pi2 = 3.14159;
    
    static_assert(pi2==pi2, "compile time error");
    assert(pi==pi2);
    
    Widget w;
    logAndProcess(w);
    logAndProcess(std::move(w));
    
    cout << boolalpha << is_lvalue<Widget>::value << endl;
    cout << boolalpha << is_lvalue<Widget&>::value << endl;
    cout << boolalpha << is_lvalue<Widget&&>::value << endl;
    
    cout << boolalpha << is_lvalue<decltype(w)>::value << endl;
    cout << boolalpha << is_lvalue<decltype(std::move(w))>::value << endl;
    
    Widget ww = std::move_if_noexcept(w);
    
    return 0;
}
