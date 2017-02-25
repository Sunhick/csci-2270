//
//  Queue.cpp
//  Queue
//
//  Created by Sunil on 2/23/17.
//  Copyright © 2017 Sunil. All rights reserved.
//

#ifndef Queue_cpp
#define Queue_cpp

#include "Queue.hpp"

#include <iostream>

using namespace std;

template<typename T>
Queue<T>::Queue() {
    reset();
}

template<typename T>
Queue<T>::~Queue() {
    reset();
}

template<typename T>
Queue<T>::Queue(Queue<T>& queue) {
    auto elements = queue.get();
    auto n = queue.filled;
    
    while(n > 0) {
        Enqueue(elements[n]);
        n--;
    }
}

template<typename T>
Queue<T>::Queue(Queue<T>&& queue) {
    container = std::move(queue.container);
    filled = queue.filled;
    head = queue.head;
    tail = queue.tail;
    queue.reset();
}

template<typename T>
typename Queue<T>::ElementType Queue<T>::Dequeue() {
    if(isEmpty()) {
        throw "Queue is empty";
    }
    
    auto value = container.get()[head];
    head = (head+1)%capacity;
    filled--;
    return value;
}

template<typename T>
void Queue<T>::Enqueue(ElementType value) {
    if (isFull()) {
        throw "Queue is full";
    }
    
    container.get()[tail] = value;
    tail = (tail+1)%capacity;
    filled++;
}

template<typename T>
bool Queue<T>::isEmpty() {
    return filled == 0;
}

template<typename T>
bool Queue<T>::isFull() {
    return filled == capacity;
}

template<typename T>
void Queue<T>::reset() {
    head = 0;
    tail = 0;
    filled = 0;
    
    container =
    std::unique_ptr<ElementType, std::function<void(ElementPtr)>>(new ElementType[capacity], [](ElementPtr ptr) {
        cout << "deleting array of " << typeid(T).name() << endl;
        delete[] ptr;
    });
}

#endif /* Queue_cpp */
