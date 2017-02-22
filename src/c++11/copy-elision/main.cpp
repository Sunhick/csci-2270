//
//  main.cpp
//  CopyElision
//
//  Created by Sunil on 2/2/17.
//  Copyright © 2017 Sunil. All rights reserved.
//

#include <iostream>

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

    return 0;
}
