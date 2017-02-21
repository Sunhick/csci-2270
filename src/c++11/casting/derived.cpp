//
//  derived.cpp
//  casting
//
//  Created by Sunil on 2/21/17.
//  Copyright © 2017 Sunil. All rights reserved.
//

#include "derived.hpp"
#include <iostream>

derived::derived(string n) : base("derived") {
    name = n;
    cout << "derived ctor" << endl;
}

derived::~derived() {
    cout << "derived dtor" << endl;
}

void derived::print() {
    cout << "derived print " << name << endl;
}

void derived::extraPrint() {
    cout << "derived extra print " << name << endl;
}
