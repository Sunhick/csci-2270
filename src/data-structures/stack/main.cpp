//
//  main.cpp
//  Stack
//
//  Created by Sunil on 2/24/17.
//  Copyright © 2017 Sunil. All rights reserved.
//

#include <iostream>

#include "Stack.hpp"

int main(int argc, const char * argv[]) {
    
    std::cout << "Stack of integers" << std::endl;
    {
        Stack<int> stack;
        std::cout << "Pusing values onto stack" << std::endl;
        for (int i = 0; i < 11; i++) {
            try {
                stack.Push(i);
                std::cout << i << std::endl;
            } catch (const char* error) {
                std::cout << error << std::endl;
            }
        }
        
        for (int i = 0; i < 11; i++) {
            try {
                std::cout << stack.Pop() << std::endl;
            } catch (const char* error) {
                std::cout << error << std::endl;
            }
        }
    }
    
    return 0;
}
