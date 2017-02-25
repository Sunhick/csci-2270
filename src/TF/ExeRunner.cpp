//
//  ExeRunner.cpp
//  TF
//
//  Created by Sunil on 2/24/17.
//  Copyright © 2017 Sunil. All rights reserved.
//

#include "ExeRunner.hpp"

#include <cstdio>
#include <memory>
#include <stdexcept>
#include <array>
#include <exception>
#include <algorithm>

#include <execinfo.h>

ExeRunner::ExeRunner(std::string exeName) {
    this->exeName = exeName;
}

ExeRunner::~ExeRunner() {
    
}

void ExeRunner::RunWithCmdLine(std::vector<std::string> args) {
    Execute();
}

void ExeRunner::Execute() noexcept(true) {
    try {
        constexpr int buffSize = 512;
        
        std::array<char, buffSize> buffer;
        std::shared_ptr<FILE> pipe(popen(exeName.c_str(), "r"), pclose);
        if (!pipe) throw std::runtime_error("popen() failed!");
        while (!feof(pipe.get())) {
            if(fgets(buffer.data(), buffSize, pipe.get()) != nullptr)
                output += buffer.data();
        }
    } catch(std::exception e) {
        hasErrors = true;
        errors = e.what();
    }
    
    if(!hasErrors) {
        // No errors during runing of the program.
        // transform the output to lower case.
        std::transform(begin(output), end(output), output.begin(), [](char c) {
            return std::tolower(c);
        });
    }
}

bool ExeRunner::HasErrors() noexcept(true) {
    return false;
}

bool ExeRunner::RanWithNoErrors() noexcept(true) {
    return true;
}

std::string ExeRunner::GetOutput() noexcept(true) {
    return output;
}
