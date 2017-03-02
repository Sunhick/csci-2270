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
        throw std::runtime_error("Queue is full");
    }
    
    arrayQueue[queueTail++] = word;
    queueTail %= queueSize;
    queueCount++;
    
    // log the entry to cout
    cout << "word: E: " << word << endl;
    cout << "H: " << queueHead << endl;
    cout << "T: " << queueTail << endl;
}

std::string Queue::dequeue() {
    if (queueIsEmpty()) {
        throw std::runtime_error("Queue is empty");
    }
    
    auto word = arrayQueue[queueHead++];
    queueHead %= queueSize;
    queueCount--;
    
    // log the entry to cout
    cout << "H: " << queueHead << endl;
    cout << "T: " << queueTail << endl;
    cout << "word: " << word << endl;
    
    return word;
}
void Queue::printQueue() {
    if (queueIsEmpty()) {
        cout << "Empty" << endl;
        return;
    }
    
    auto index = queueHead;
    auto printCount = queueCount;
    while (printCount) {
        cout << index << ": " << arrayQueue[index] << endl;
        index = (index+1) % queueSize;
        printCount--;
    }
}

bool Queue::queueIsFull() {
    return queueCount == queueSize;
}

bool Queue::queueIsEmpty() {
    return queueCount == 0;
}
