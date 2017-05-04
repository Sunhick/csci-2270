//
//  main.cpp
//  builtins
//
//  Created by Sunil on 5/3/17.
//  Copyright © 2017 Sunil. All rights reserved.
//

#include <iostream>

using namespace std;

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
    
    return 0;
}
