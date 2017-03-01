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

class Process {
public:
    int id;
    std::string moniker;
    
    ~Process();
    Process(int id, string moniker);
    explicit Process(int id);
    
    string GetMoniker();
    int GetId();
};

#endif /* Process_hpp */
