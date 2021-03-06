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
#include <fstream>
#include <stdexcept>

#include <sys/stat.h>
#include <dirent.h>
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
        std::ifstream file(exeName);
        if(file.fail()) {
            throw std::runtime_error("File doesn't exists!");
        }
        
        struct stat sb;
        if(stat(exeName.c_str(), &sb) != 0 || !(sb.st_mode & S_IXUSR)) {
            throw std::runtime_error("File is not executable!");
        }
        if(sb.st_mode & S_IFDIR) {
            throw std::runtime_error("You passed a directory!");
        }
        
        constexpr int buffSize = 512;
        std::array<char, buffSize> buffer;
        std::shared_ptr<FILE> pipe(popen(exeName.c_str(), "r"), pclose);
        if (!pipe) throw std::runtime_error("popen() failed!");
        while (!feof(pipe.get())) {
            if(fgets(buffer.data(), buffSize, pipe.get()) != nullptr)
                output += buffer.data();
        }
    } catch(const std::exception& e) {
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
    return hasErrors;
}

bool ExeRunner::RanWithNoErrors() noexcept(true) {
    return true;
}

std::string ExeRunner::GetOutput() noexcept(true) {
    return output;
}

std::string ExeRunner::GetErrors() noexcept(true) {
    return errors;
}
