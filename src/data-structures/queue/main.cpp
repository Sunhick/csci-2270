//
//  main.cpp
//  Queue
//
//  Created by Sunil on 2/23/17.
//  Copyright © 2017 Sunil. All rights reserved.
//

#include <iostream>

#include "Queue.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    
    Queue<int> queue;
    
    cout << "Enqueuing..." << endl;
    {
        for(int i = 0; i < 11; i++) {
            try {
                cout << i+99 << endl;
                queue.Enqueue(i+99);
            } catch (const char* e) {
                cout << e << endl;
            }
        }
    }
    
    cout << "Dequeuing..." << endl;
    {
        for(int i = 0; i < 11; i++) {
            try {
                cout << queue.Dequeue() << endl;
            } catch (const char* e) {
                cout << e << endl;
            }
        }
    }
    
    cout << "Enqueuing..." << endl;
    {
        for(int i = 0; i < 11; i++) {
            try {
                queue.Enqueue(i+99);
                cout << i+99 << endl;
            } catch (const char* e) {
                cout << e << endl;
            }
        }
    }
    
    cout << "Queue of strings" << endl;
    {
        Queue<std::string> strs;
        strs.Enqueue("Hello 1");
        strs.Enqueue("Hello 2");
        strs.Enqueue("Hello 3");
        strs.Enqueue("Hello 4");
        strs.Enqueue("Hello 5");
        strs.Enqueue("Hello 6");
        strs.Enqueue("Hello 7");
        strs.Enqueue("Hello 8");
        strs.Enqueue("Hello 9");
        strs.Enqueue("Hello 10");
        
        Queue<string> p((strs));
        
        while(!strs.isEmpty()) {
            try {
                cout << strs.Dequeue() << endl;
                cout << strs.Dequeue() << endl;
                strs.Enqueue("Dequeue print");

            } catch (const char* error) {
                cout << error << endl;
            }
        }
        
        while(!p.isEmpty()) {
            try {
                cout << p.Dequeue() << endl;
                cout << p.Dequeue() << endl;
                p.Enqueue("Dequeue print");
                
            } catch (const char* error) {
                cout << error << endl;
            }
        }
    }
    
    return 0;
}
