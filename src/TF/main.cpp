//
//  main.cpp
//  TF
//
//  Created by Sunil on 2/24/17.
//  Copyright © 2017 Sunil. All rights reserved.
//

#include <iostream>
#include <vector>

#include "ExeRunner.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    ExeRunner runner("");
    runner.RunWithCmdLine({""});
    
    if(!runner.HasErrors()) {
        // compare output
        cout << runner.GetOutput() << endl;
    }
    
    return 0;
}
