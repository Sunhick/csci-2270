//
//  ExeRunner.hpp
//  TF
//
//  Created by Sunil on 2/24/17.
//  Copyright © 2017 Sunil. All rights reserved.
//

#ifndef ExeRunner_hpp
#define ExeRunner_hpp

#include <iostream>
#include <vector>
#include <string>

// Runs another executable as a separate process
// and get's the program output.
class ExeRunner {
private:
    std::string output;
    std::string exeName;
    std::vector<std::string> cmdlineArgs;
    
    bool hasErrors;
    std::string errors;
    
public:
    ExeRunner(std::string);
    ~ExeRunner();
    
    void Execute() noexcept(true);
    void RunWithCmdLine(std::vector<std::string>);
    bool HasErrors() noexcept(true);
    bool RanWithNoErrors() noexcept(true);
    
    std::string GetErrors() noexcept(true);
    std::string GetOutput() noexcept(true);
};

#endif /* ExeRunner_hpp */
