//
//  main.cpp
//  explicit
//
//  Created by Sunil on 2/25/17.
//  Copyright © 2017 Sunil. All rights reserved.
//

#include <iostream>
#include <string>

#include "Process.hpp"

using namespace std;

void Modify(Process p) {
    cout << p.GetId() << p.GetMoniker() << endl;
    // modify here
}

int main(int argc, const char * argv[]) {

    // implicit conversion allowed by compilers.
    // with explicit keyword it's disallowed and
    // object has to explicitly created.
    // Modify(5656);
    
    // explicit object creation
    Modify(Process(5656));
    return 0;
}
