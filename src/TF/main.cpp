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
#include "ColorConsole.hpp"

using namespace std;

const char* usage = "Didn't specify the executable! \n\n"
                    "Usage:\n"
                    "\t$ ./test [Executable] [Command line args] \n\n"
                    "Example:\n"
                    "\t$./test Assignment3 messageIn.txt\n\n";

int main(int argc, const char * argv[]) {
    if (argc < 2) {
        cout << RED << usage << RESET;
        return 0;
    }
    
    cout << GREEN;
    cout << endl << "Executable name: " << argv[1] << endl;
    cout << "Command line arguments: ";
    int count = 2;
    while (count < argc) {
        cout << argv[count++] << " ";
    }
    cout << endl << RESET;
    
    ExeRunner runner(argv[1]);
    runner.RunWithCmdLine({""});
    
    if(!runner.HasErrors()) {
        // compare output
        cout << BLUE << runner.GetOutput() << RESET << endl;
        cout << BOLDGREEN << "** All test cases passed **" << RESET << endl;
    }
    
    return 0;
}
