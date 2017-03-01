//
//  Grader.cpp
//  TF
//
//  Created by Sunil on 2/25/17.
//  Copyright © 2017 Sunil. All rights reserved.
//

#include "Grader.hpp"

Grader::Grader() {
    score = 0;
}

bool Grader::CheckOutput(std::string expected, std::string got, int points) {
    auto status = expected == got;
    if(status) {
        score += points;
    } else {
        throw std::runtime_error("Got different output!");
    }
    return status;
}
