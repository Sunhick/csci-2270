//
//  Stack.hpp
//  Stack
//
//  Created by Sunil on 2/24/17.
//  Copyright © 2017 Sunil. All rights reserved.
//

#ifndef Stack_hpp
#define Stack_hpp

#include <iostream>
#include <memory>
#include <functional>

template <typename T>
class Stack {
public:
    using ElementType = T;
    using ElementPtr = T*;
    using ElementRef = T&;
    
    Stack();
    Stack(Stack<T>&);
    Stack(Stack<T>&&);
    ~Stack();
    
    void Push(ElementType);
    ElementType Pop();
    ElementType Peek();
    bool isFull();
    bool isEmpty();

private:
    int count;
    static constexpr int capacity = 10;
    std::unique_ptr<ElementType, std::function<void(ElementPtr)>> container;
    
    void reset();
};

#include "Stack.cpp"

#endif /* Stack_hpp */
