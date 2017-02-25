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
#include "TermColor.hpp"

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
    
    cout << endl << "=============== ARGS ===============" << endl;
    cout << "Executable name: " << termcolor::green << argv[1] << termcolor::reset << endl;
    cout << "Command line arguments: ";
    int count = 2;
    cout << termcolor::green;
    while (count < argc) {
        cout << argv[count++] << " ";
    }
    cout << termcolor::reset << endl;
    
    ExeRunner runner(argv[1]);
    runner.RunWithCmdLine({""});
    
    cout << endl << "=============== ERRORS ===============" << endl;
    if(runner.HasErrors()) {
        cout << termcolor::bold << termcolor::red << "Error running '" << argv[1] << "' program" << termcolor::reset << endl;
        cout << termcolor::red << runner.GetErrors() << termcolor::reset << endl;
        cout << termcolor::red << runner.GetOutput() << termcolor::reset << endl;
        return 0;
    } else {
        cout << termcolor::green << "No errors! :) " << termcolor::reset << endl;
    }
    
    cout << endl << "=============== OUTPUT ===============" << endl;
    // compare output
    cout << termcolor::blue << runner.GetOutput() << RESET << endl;
    cout << termcolor::green << termcolor::bold << "** All test cases passed **" << RESET << endl;
    
    return 0;
}
