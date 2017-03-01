//
//  Queue.cpp
//  CircularQueue
//
//  Created by Sunil on 2/25/17.
//  Copyright © 2017 Sunil. All rights reserved.
//

#include "Queue.h"

using namespace std;

Queue::Queue(int qs) {
    queueSize = qs;
    arrayQueue = new std::string[queueSize];
    queueHead = 0;
    queueTail = 0;
}

Queue::~Queue() {
    delete [] arrayQueue;
    arrayQueue = nullptr;
}

//circular queue methods
void Queue::enqueue(std::string word) {
    if (queueIsFull()) {
        cout << "Queue is full" << endl;
        return;
    }
    
    arrayQueue[queueTail++] = word;
    queueTail %= queueSize;
    queueCount++;
    
    // log the entry to cout
    cout << "E: " << word << endl;
    cout << "H: " << queueHead << endl;
    cout << "T: " << queueTail << endl;
}

std::string Queue::dequeue() {
    if (queueIsEmpty()) {
        cout << "Queue is empty" << endl;
        return "";
    }
    auto word = arrayQueue[queueHead++];
    queueHead %= queueSize;
    queueCount--;
    
    // log the entry to cout
    cout << "E: " << word << endl;
    cout << "H: " << queueHead << endl;
    cout << "T: " << queueTail << endl;
    
    return word;
}
void Queue::printQueue() {
    auto index = queueHead;
    while (index != queueTail) {
        cout << index << ": " << arrayQueue[index] << endl;
        index = (index+1) % queueSize;
    }
}

bool Queue::queueIsFull() {
    return queueCount == queueSize;
}

bool Queue::queueIsEmpty() {
    return queueCount == 0;
}
