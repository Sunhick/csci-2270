//
//  TermColor.hpp
//  TF
//
//  Created by Sunil on 2/24/17.
//  Copyright © 2017 Sunil. All rights reserved.
//

#ifndef TermColor_hpp
#define TermColor_hpp

#include <iostream>
#include <cstdio>
#include <unistd.h>
#include <functional>

//Mac/Linux terminal color codes.
#define RESET           "\033[0m"
#define BLACK           "\033[30m"
#define RED             "\033[31m"
#define GREEN           "\033[32m"
#define YELLOW          "\033[33m"
#define BLUE            "\033[34m"
#define MAGENTA         "\033[35m"
#define CYAN            "\033[36m"
#define WHITE           "\033[37m"
#define BOLD            "\033[1m"
#define DARK            "\033[2m"
#define UNDERLINE       "\033[4m"

namespace termcolor {
    // check if ostream supports term colors
    bool isterminal(const std::ostream& stream);
    
    template<const char* color>
    std::ostream& setcolor(std::ostream& stream);
    
    
    // using func = std::function<std::ostream&(std::ostream&)>;
    // using black = setcolor<BLACK>;
    // std::ostream& (&black)(std::ostream&) = setcolor<BLACK>;
    // void black () __attribute__ ((weak, alias ("setcolor<BLACK>")));
    // using func = void(*)(int);
    
    // terminal colors
    std::ostream& black(std::ostream& stream);
    std::ostream& green(std::ostream& stream);
    std::ostream& yellow(std::ostream& stream);
    std::ostream& blue(std::ostream& stream);
    std::ostream& magenta(std::ostream& stream);
    std::ostream& cyan(std::ostream& stream);
    std::ostream& white(std::ostream& stream);
    std::ostream& red(std::ostream& stream);
    
    // styles
    std::ostream& reset(std::ostream& stream);
    std::ostream& bold(std::ostream& stream);
    std::ostream& dark(std::ostream& stream);
    std::ostream& underline(std::ostream& stream);
}



#endif /* TermColor_hpp */
