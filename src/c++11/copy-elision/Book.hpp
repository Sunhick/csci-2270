//
//  Book.hpp
//  CopyElision
//
//  Created by Sunil on 2/21/17.
//  Copyright © 2017 Sunil. All rights reserved.
//

#ifndef Book_hpp
#define Book_hpp

#include <string>

using namespace std;

class Book {
private:
    string name;
    int pages;

public:
    Book();                     // default ctor
    Book(string n, int p);      // parameter ctor
    Book(const Book& book);     // copy ctor
    Book(Book&& book);          // move ctor
    Book& operator=(const Book& book);  // assignment ctor
    
    ~Book();
};

#endif /* Book_hpp */
