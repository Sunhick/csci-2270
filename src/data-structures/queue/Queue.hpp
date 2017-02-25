//
//  Queue.hpp
//  Queue
//
//  Created by Sunil on 2/23/17.
//  Copyright © 2017 Sunil. All rights reserved.
//

#ifndef Queue_hpp
#define Queue_hpp

#include <memory>
#include <functional>

template<typename T>
class Queue {
public:
    using ElementType = T;
    using ElementPtr = T*;
    using ElementRef = T&;
    static constexpr int capacity = 10;
    
    Queue();
    Queue(Queue<T>&);
    Queue(Queue<T>&&);
    ~Queue();
    
    ElementType Dequeue();
    void Enqueue(ElementType);
    bool isFull();
    bool isEmpty();
    
private:
    std::unique_ptr<ElementType, std::function<void(ElementPtr)>> container;
    int head;
    int tail;
    int filled;
    
    void reset();
};

#include "Queue.cpp"

#endif /* Queue_hpp */
