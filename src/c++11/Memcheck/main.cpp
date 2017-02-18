//
//  main.cpp
//  Memcheck
//
//  Created by Sunil on 2/17/17.
//  Copyright © 2017 Sunil. All rights reserved.
//

#include <iostream>
#include "memcheck.h"

using namespace std;

struct word {
    std::string w;
    int count;
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n" << sizeof(word) << endl;
    word *w  = new word;
    word *w2  = new word;
    word *w3 = new word[10];
    
    w->w = "hello";
    w->count = 45;
    
    cout << w->w << w->count << endl;
    
    delete w;
    delete w2;
   // delete [] w3;
    
    return 0;
}
