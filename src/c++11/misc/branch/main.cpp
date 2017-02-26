//
//  main.cpp
//  new
//
//  Created by Sunil on 2/25/17.
//  Copyright © 2017 Sunil. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <memory>

// placement new
// cite: http://madebyevan.com/obscure-cpp-features/
#include "Process.hpp"

using namespace std;

void KillProcess(Process* p) {
//    auto or auto* works! Due to type deduction rules
//    auto* sys = dynamic_cast<SystemProcess*>(p);
//    if (sys) {
//        cout << "invoke system process kill" << endl;
//        sys->kill();
//    }
//    
//    auto* user = dynamic_cast<UserProcess*>(p);
//    if(user) {
//        cout << "invoke user process kill" << endl;
//        user->kill();
//    }

//    Branch on variable declaration
//    The above calls can be more compactly written as,

    if(auto* sys = dynamic_cast<SystemProcess*>(p)) {
        cout << "invoke system process kill" << endl;
        sys->kill();
    }
    
    if(auto* user = dynamic_cast<UserProcess*>(p)) {
        cout << "invoke user process kill" << endl;
        user->kill();
    }
}

int main(int argc, const char * argv[]) {

    vector<shared_ptr<Process>> processes =
    {
        shared_ptr<Process>(new SystemProcess(1212)),
        shared_ptr<Process>(new UserProcess(3434))
    };
    
    for(auto& p : processes) {
        KillProcess(p.get());
    }
    
    return 0;
}
