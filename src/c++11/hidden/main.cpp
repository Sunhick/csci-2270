//
//  main.cpp
//  builtins
//
//  Created by Sunil on 5/3/17.
//  Copyright © 2017 Sunil. All rights reserved.
//

#include <iostream>

using namespace std;

struct Foo {
    string name;
    int id;
};

void bar(Foo f) {
    cout << f.name << " " << f.id << endl;
}

int main(int argc, const char * argv[]) {
    
    // function with __builtin_xxx are hidden. But not really! They are still
    // available. You can call them. Are they platform specific ? I don't know.
    
    // List of builtin functions: http://www.keil.com/support/man/docs/armcc/armcc_chr1359125006834.htm
    auto ffs = __builtin_ffs(10);
    auto clz = __builtin_clz(10);
    auto popcount = __builtin_popcount(10);
    auto gcd = __gcd(10, 8);
    
    cout << "ffs: " << ffs << endl;
    cout << "clz: " << clz << endl;
    cout << "popcount: " << popcount << endl;
    cout << "gcd: " << gcd << endl;
    
    
    // odd expressions in c++ arrays
    const char* name = "welcome to UC boulder!";
    cout << name << endl;
    
    char x = "Hello" " " "World"[8];
    cout << x << endl;
    
    char y = 8["Hello" " " "World"];
    cout << y << endl;
    
    // crazy ternary operator
    int a = 7;
    int b = 8;
    
    ((a < b) ? a : b) = -((a > b) ? a : b);
    
    cout << a << " " << b << endl;
    
    
    // You think you have mastered for (...) loop ?
    // take a look at the below for loop & think again!
    for (struct {int min; int max;} i = {0, 10}; i.min < i.max; i.min++) {
        cout << i.min << endl;
    }
    
    // I got you now, didn't I ? Haha.
    bar(*(new Foo {"sunil", 45}));
    // wait, I got into my own hell. How do I delete Foo now ??
    
    return 0;
}
