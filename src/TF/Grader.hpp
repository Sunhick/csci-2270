//
//  Grader.hpp
//  TF
//
//  Created by Sunil on 2/25/17.
//  Copyright © 2017 Sunil. All rights reserved.
//

#ifndef Grader_hpp
#define Grader_hpp

#include <iostream>

class Grader {
private:
    int score;
    static constexpr int total = 100;
    
public:
    Grader();
    
    bool CheckOutput(std::string, std::string, int);
};

#endif /* Grader_hpp */
