//
//  main.cpp
//  CircularQueue
//
//  Created by Sunil on 2/25/17.
//  Copyright © 2017 Sunil. All rights reserved.
//

#include <iostream>
#include <string>
#include <sstream>

#include "Queue.h"

using namespace std;

int main(int argc, const char * argv[]) {
    
    std::string dmenu = "======Main Menu======\n"
                        "1. Enqueue word\n"
                        "2. Dequeue word\n"
                        "3. Print queue\n"
                        "4. Enqueue sentence\n"
                        "5. Quit";
    
    int choice;
    bool exit = false;
    Queue queue(10);
    
    cout << dmenu << endl;
    
    while(cin >> choice) {
        
        // flush the newlines and other characters
        cin.clear();
        cin.ignore();
        
        switch (choice) {
            case 1:
            {
                std::string word;
                std::getline(cin, word);
                queue.enqueue(word);
                break;
            }
            
            case 2:
            {
                queue.dequeue();
                break;
            }
                
            case 3:
            {
                queue.printQueue();
                break;
            }
                
            case 4:
            {
                std::string sentence;
                std::string word;
                
                std::getline(cin, sentence);
                std::istringstream stream(sentence);
                
                cout << "sentence: " << sentence << endl;
                while(std::getline(stream, word, ' ')) {
                    queue.enqueue(word);
                }
                
                break;
            }
                
            case 5:
            {
                exit = true;
                break;
            }
        }
        
        if (exit) {
            break;
        }
        
        cout << dmenu << endl;
    }
    
    cout << "Goodbye" << endl;
    return 0;
}
