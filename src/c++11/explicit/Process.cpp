//
//  Process.cpp
//  explicit
//
//  Created by Sunil on 2/25/17.
//  Copyright © 2017 Sunil. All rights reserved.
//

#include "Process.hpp"

Process::Process(int id, string moniker) {
    this->id = id;
    this->moniker = moniker;
}

Process::Process(int id) : Process(id, "<default>") {
}

string Process::GetMoniker() {
    return moniker;
}

int Process::GetId() {
    return id;
}
