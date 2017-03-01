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
    
    Process p(5656, "lvalue-object");
    p.foo();
    p.foo("lvalue");
    
    // p becomes invalid after the below call.
    // This is only for demonstration purposes only.
    move(p).foo("lvalue");
    
    Process(4545, "rvalue-object").foo();
    Process(4556, "rvalue-object-2").foo("rvalue");
    return 0;
}
