//
//  main.cpp
//  Test11
//
//  Created by Sunil on 2/25/17.
//  Copyright © 2017 Sunil. All rights reserved.
//

#include <iostream>
#include <mutex>

using namespace std;

#define nameof(x) #x

// strongly typed enums
enum class LogType {
    Debug,
    Error,
    Warning,
    Fatal
};

int main(int argc, const char * argv[]) {
    
    cout << "C++ macro value: " << __cplusplus << endl;
    cout << nameof(LogType::Error) << endl;
    
    LogType type = LogType::Debug;
    switch (type) {
        case LogType::Error:
            // handle error
            break;
        
        case LogType::Debug:
            // handle debug
            break;
            
        default:
            break;
    }
    // type = 45; // error

    int value = 9;
    
    // locking
    std::recursive_mutex m;
    
    m.lock();
    value++;
    
    m.lock();
    value++;
    
    cout << value << endl;
    
    
    return 0;
}
