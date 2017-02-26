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

// cite: http://madebyevan.com/obscure-cpp-features/
#include "Process.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    
    Process p(560);
    cout << p.GetMoniker() << endl;
    return 0;
}
