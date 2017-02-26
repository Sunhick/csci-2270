//
//  Process.cpp
//  new
//
//  Created by Sunil on 2/25/17.
//  Copyright © 2017 Sunil. All rights reserved.
//

#include "Process.hpp"
#include <iostream>

using namespace std;

Process::Process(int id, string moniker) try : id(validate(id)) {
    this->id = id;
    this->moniker = moniker;
} catch(const char* e) {
    cout << "Caught in ctor: " << e << endl;
}

int Process::validate(int id) {
    if(id < 0) throw "Negative id are not allowed!";
    return id;
}

Process::Process(int id) : Process(id, "<default>") {
}

string Process::GetMoniker() try {
    throw "error in moniker";
    return moniker;
} catch(...) {
    cout << "error in get moniker" << endl;
    return moniker;
}

int Process::GetId() {
    return id;
}

void Process::kill() {
    cout << "Killing process\n";
}
