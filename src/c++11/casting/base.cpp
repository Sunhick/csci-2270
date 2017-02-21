//
//  base.cpp
//  casting
//
//  Created by Sunil on 2/21/17.
//  Copyright © 2017 Sunil. All rights reserved.
//

#include "base.hpp"

#include <iostream>

base::base(string n) {
    name = n;
    cout << "base param ctor" << endl;
}

base::base() {
    cout << "base ctor" << endl;
}

base::~base() {
    cout << "base dtor" << endl;
}

void base::print() {
    cout << "base print " << name << endl;
}
