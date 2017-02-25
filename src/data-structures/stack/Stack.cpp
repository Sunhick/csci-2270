//
//  Stack.cpp
//  Stack
//
//  Created by Sunil on 2/24/17.
//  Copyright © 2017 Sunil. All rights reserved.
//

#ifndef Stack_cpp
#define Stack_cpp

#include "Stack.hpp"

template<typename T>
Stack<T>::Stack() {
    reset();
}

template<typename T>
Stack<T>::Stack(Stack<T>& stack) {
    auto elements = stack.container.get();
    int index = 0;
    while(index < stack.count) {
        Push(stack[index++]);
    }
}

template<typename T>
Stack<T>::Stack(Stack<T>&& stack) {
    count = stack.count;
    container = std::move(stack.container);
    stack.container = nullptr;
    stack.count = 0;
}

template<typename T>
Stack<T>::~Stack() {
    container = nullptr;
    count = 0;
}

template<typename T>
void Stack<T>::Push(ElementType value) {
    if(isFull()) {
        throw "Stack overflow";
    }
    
    container.get()[count++] = value;
}

template<typename T>
typename Stack<T>::ElementType Stack<T>::Pop() {
    if(isEmpty()) {
        throw "Stack underflow";
    }
    
    return container.get()[--count];
}

template<typename T>
typename Stack<T>::ElementType Stack<T>::Peek() {
}

template<typename T>
bool Stack<T>::isFull() {
    return count == capacity;
}

template<typename T>
bool Stack<T>::isEmpty() {
    return count == 0;
}

template<typename T>
void Stack<T>::reset() {
    container =
    std::unique_ptr<ElementType, std::function<void(ElementPtr)>>(new ElementType[capacity], [](ElementPtr ptr) {
        delete[] ptr;
    });
    count = 0;
}

#endif /* Stack_cpp */
