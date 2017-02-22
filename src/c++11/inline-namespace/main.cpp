//
//  main.cpp
//  inline namespace : function versioning (libraries)
//
//  Created by Sunil on 2/21/17.
//  Copyright © 2017 Sunil. All rights reserved.
//

#include <iostream>
#include "Library.hpp"

using namespace std;
using namespace Utils;

decltype(std::current_exception()) err() {
    try {
        throw "error";
    } catch (...) {
        // cout << "err:" << e << endl;
        return std::current_exception();
    }
}

int main(int argc, const char * argv[]) {
    
    std::exception_ptr p;
    try {
        throw "some logic_error exception";
    } catch(...) {
        p = std::current_exception();
        std::cout << "exception caught, but continuing...\n";
    }
    
    std::cout << "after exception\n";
    
    try {
        std::rethrow_exception (p);
    } catch (const char* e) {
        std::cout << "exception caught: " << e << '\n';
    }
    
    cout << "v99" << endl;
    {
        int a = V99::add(19, 19);
        cout << a << endl;
    }
    
    cout << "v98" << endl;
    {
        int b = V98::add(19, 19);
        cout << b << endl;
    }
    
    cout << "v99" << endl;
    {
        int c = add(19,10);
        cout << c << endl;
    }
    
    return 0;
}
