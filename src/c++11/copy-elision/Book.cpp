//
//  Book.cpp
//  CopyElision
//
//  Created by Sunil on 2/21/17.
//  Copyright © 2017 Sunil. All rights reserved.
//

#include "Book.hpp"

#include <iostream>

using namespace std;

Book::Book() {
    cout << "parameterless ctor" << endl;
}

Book::Book(string n, int p) {
    name = n;
    pages = p;
    cout << "parameter ctor" << endl;
}


Book::Book(const Book& book) {
    cout << "copy ctor" << endl;
}

Book::Book(Book&& book) {
    cout << "move ctor" << endl;
}

Book& Book::operator=(const Book& book) {
    cout << "assignment ctor" << endl;
    return *this;
}

Book::~Book() {
    // cout << "dtor" << endl;
}
