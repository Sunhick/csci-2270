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

Process::Process(int id, string moniker) {
    this->id = id;
    this->moniker = moniker;
}

Process::Process(int id) : Process(id, "<default>") {
}

Process::~Process() {
    cout << "In process dtor" << endl;
}

string Process::GetMoniker() {
    return moniker;
}

int Process::GetId() {
    return id;
}

void SystemProcess::kill() {
    cout << "Killing system process\n";
}

SystemProcess::~SystemProcess() {
    cout << "in system process dtor\n";
}

void UserProcess::kill() {
    cout << "Killing user process\n";
}

UserProcess::~UserProcess() {
    cout << "in user process dtor\n";
}
