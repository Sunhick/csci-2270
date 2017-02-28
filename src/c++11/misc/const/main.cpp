//
//  main.cpp
//  new
//
//  Created by Sunil on 2/25/17.
//  Copyright © 2017 Sunil. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <memory>

#include "Process.hpp"

using namespace std;

class Temp {
private:
    const int value;
    int *ptr;
public:
    Temp();
    int Getvalue() { return value; }
};

Temp::Temp() : value(99) {
    // const_cast is evil!
    // auto proxy = const_cast<int*>(&value);
    // *proxy = 55;
    
    ptr = new int;
    
    // hacky way to change const value
    // invoke constructor on the raw memory buffer
    new((int*)&value) int(9);
    
    // Same as const_cast but using C style constructs
    int *ts = (int*)&value;
    *ts = 56;
    
    // you can also change value by redefining the keywords as
    // #define const volatile
    // #define private public
    //    class Test {
    //    private:
    //        const int value;
    //    ...
    //    }
    // #undef const
    // #undef private
    //
    //   Test t;
    //   t.k = 98; 
    
    cout << value << endl;
}

void change1(int* p) {
    cout << &p << endl << p << endl;
    p = new int(56);
    cout << &p << endl << p << endl;
}

void change2(int** p) {
    cout << &p << endl << p << endl << *p << endl;
    *p = new int(56);
    cout << &p << endl << p << endl << *p << endl;
}

void change3(int*& p) {
    cout << &p << endl << p << endl;
    p = new int(56);
    cout << &p << endl << p << endl;
}

int main(int argc, const char * argv[]) {
    
    Temp t;
    cout << t.Getvalue() <<endl;
    
    int *i = new int(99);
    change3(i);
    cout << &i << endl << i  << endl << *i << endl;
    
    return 0;
}
