//
//  main.cpp
//  CopyElision
//
//  Created by Sunil on 2/2/17.
//  Copyright © 2017 Sunil. All rights reserved.
//

#include <iostream>
#include <cassert>
#include "Book.hpp"

using namespace std;

// Named Return value optimization (NRVO)
Book makeBook() {
    Book b;
    return b;
}

// Return value optimization (RVO)
Book makeBook2() {
    return {};
    // same as return Book();
}

void process(Book b) noexcept(true) {
    // temporary object
}

void process2() noexcept(false) {
    Book b;
    throw b;
}

template<class T, template<T value> class V>
struct negate2 {
    static const T value = -value;
};

template<class T, T v>
struct negate3 {
    static const T value = -v;
};

template<class T>
struct negate4 {
    T operator()(T v) {
        return static_cast<T>(-v);
    }
};

int main() {
    std::cout << "Copy elision: Is a copy omission."
                 "It's a compiler optimization to avoid unnecessary copying of objects."
                 "To override g++ use -fno-elide-constructors flag." << endl;
    {
        Book b;
        Book b1 = b;
        b1 = b;
        Book b2(b);
        Book b3 {b};
        Book b4(move(b));
        Book b5 = move(b);
        Book b6 {move(b)};
        Book b7 = {move(b)};
        Book b8 = {"comic", 500};
        
        cout << "-----COPY ELISION-----" << endl;
        Book k1 = makeBook();
        Book k2 = makeBook2();
        process(Book());
        
        cout << "----TRY CATCH-----" << endl;
        try {
            process2();
        } catch (Book f) {
            cout << "caught" << endl;
        }
    }
    
    // cout << negate2<-23>::value << endl << negate2<23>::value << endl;
    cout << negate3<int, 45>::value << endl;
    
    // cout << negate3<double, -45.4545>::value << endl; // error: float , char* cann't be template params
    // cout << negate4<double>(-45.4545) << endl;
    cout << negate4<double>()(67.67676767) << endl;
    
    // no narrowing c++ {} initialization
    // int x {45.45};  // error
    // cout << x << endl;
    
    int *p = new int;
    // runtime time assert
    assert(p != nullptr);
    
    // compile time assert
    static_assert(sizeof(int*)==8, "pointer size should 8 bytes!");

    return 0;
}
