//
//  TermColor.cpp
//  TF
//
//  Created by Sunil on 2/24/17.
//  Copyright © 2017 Sunil. All rights reserved.
//

#include "TermColor.hpp"

#include <stdio.h>
#include <iostream>

using namespace std;

namespace termcolor {

bool isterminal(const std::ostream& stream) {
    auto file = (&stream == &std::cout) ? stdout :
                (&stream == &std::cerr) ? stderr : nullptr;
    return ::isatty(fileno(file));
}

// set color
template<const char* color>
std::ostream& setcolor(std::ostream& stream) {
    if(!termcolor::isterminal(stream)) return stream;
    stream << color;
    return stream;
}
    
std::ostream& black(std::ostream& stream) {
    if(!termcolor::isterminal(stream)) return stream;
    stream << BLACK;
    return stream;
    // return termcolor::setcolor<BLACK>(stream);
}

std::ostream& green(std::ostream& stream) {
    if(!termcolor::isterminal(stream)) return stream;
    stream << GREEN;
    return stream;
}

std::ostream& yellow(std::ostream& stream) {
    if(!termcolor::isterminal(stream)) return stream;
    stream << YELLOW;
    return stream;
}

std::ostream& blue(std::ostream& stream) {
    if(!termcolor::isterminal(stream)) return stream;
    stream << BLUE;
    return stream;
}

std::ostream& magenta(std::ostream& stream) {
    if(!termcolor::isterminal(stream)) return stream;
    stream << MAGENTA;
    return stream;
}

std::ostream& cyan(std::ostream& stream) {
    if(!termcolor::isterminal(stream)) return stream;
    stream << CYAN;
    return stream;
}

std::ostream& white(std::ostream& stream) {
    if(!termcolor::isterminal(stream)) return stream;
    stream << WHITE;
    return stream;
}

// styles
std::ostream& reset(std::ostream& stream) {
    if(!termcolor::isterminal(stream)) return stream;
    stream << RESET;
    return stream;
}

std::ostream& bold(std::ostream& stream) {
    if(!termcolor::isterminal(stream)) return stream;
    stream << BOLD;
    return stream;
}

std::ostream& dark(std::ostream& stream) {
    if(!termcolor::isterminal(stream)) return stream;
    stream << DARK;
    return stream;
}

std::ostream& underline(std::ostream& stream) {
    if(!termcolor::isterminal(stream)) return stream;
    stream << UNDERLINE;
    return stream;
}

std::ostream& red(std::ostream& stream) {
    if(!termcolor::isterminal(stream)) return stream;
    stream << RED;
    return stream;
}
    
} // namespace termcolor
