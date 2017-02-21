//
//  main.cpp
//  SmartPointers
//
//  Created by Sunil on 2/20/17.
//  Copyright © 2017 Sunil. All rights reserved.
//

#include <iostream>
#include <unistd.h>

#include "Logger.h"
#include "Family.h"

using namespace std;
using namespace Logging;
using namespace Family;

int main(int argc, const char * argv[]) {
    // cout << getcwd(nullptr, 0) << endl;
    
    Logger log("/Users/Sunny/prv/tmp/SmartPointers/log.txt");
    log << "Hello Sunil" << "Another log";
    log << "Hello Welcome to word" << "Welcome log";
    
    Logger log2(log);
    log2 << "Other logger 1";
    log2 << "Other logger 2";
    // log << "Hello Sunil" << "Another log"; Error. log object is scarred.
    
    shared_ptr<Wife> mary(new Wife("mary"));
    shared_ptr<Husband> john(new Husband("John", mary));
    mary->SetHusband(john);
    
    john->PrintCouples();
    mary->PrintCouples();
    
    
    return 0;
}
