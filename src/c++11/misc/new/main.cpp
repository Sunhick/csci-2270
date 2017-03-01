//
//  main.cpp
//  new
//
//  Created by Sunil on 2/25/17.
//  Copyright © 2017 Sunil. All rights reserved.
//

#include <iostream>
#include <string>

// placement new
// cite: http://madebyevan.com/obscure-cpp-features/
#include "Process.hpp"

using namespace std;

int main(int argc, const char * argv[]) {

    // Process* ptr = new Process(5656);
    // Above line is the short hand for below two lines
    
    // Allocate memory using malloc
    Process* ptr = (Process*)malloc(sizeof(Process));
    // call to constructor
    new(ptr) Process(5656);
    
    const Process* ptr2 = new Process(5667, "12.api.34");
    // ptr2->id = 7777; // can't do this because ptr2 is pointing to const Process object
    // However, I can change the values by re-calling the constructors on the same memory as,
    new((Process*)ptr2) Process(4545, "changed.it.4545");
    // ptr2 is still the same object however i changed the values
    
    // delete ptr;
    // delete ptr2;
    // delete is a short hand for the below two calls, dtor and free()
    ptr->~Process();
    ptr2->~Process();
    
    free(ptr);
    free((Process*)ptr2);
    
    return 0;
}
