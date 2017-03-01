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
    virtual void kill() = 0;
};

// System process
class SystemProcess : public Process {
public:
    SystemProcess(int id) : Process(id) {}
    ~SystemProcess();
    virtual void kill() override;
};

// user process
class UserProcess : public Process {
public:
    UserProcess(int id) : Process(id) {}
    ~UserProcess();
    virtual void kill() override;
};

#endif /* Process_hpp */
