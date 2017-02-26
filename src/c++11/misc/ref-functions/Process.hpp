//
//  Process.hpp
//  new
//
//  Created by Sunil on 2/25/17.
//  Copyright © 2017 Sunil. All rights reserved.
//

#ifndef Process_hpp
#define Process_hpp

#include <string>

using namespace std;

// Generic process
class Process {
protected:
    int id;
    std::string moniker;
public:
    ~Process();
    Process(int id, string moniker);
    explicit Process(int id);
    
    string GetMoniker();
    int GetId();
    virtual void kill();
    
    // ref qualifiers on member function
    void foo() &;   // called from lvalue
    void foo() &&;  // called from rvalue
    
    // overload on ref qualifiers
    void foo(string) &;
    void foo(string) &&;
    
};

#endif /* Process_hpp */
