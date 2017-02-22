//
//  Library.hpp
//  inline namespace : function versioning (libraries)
//
//  Created by Sunil on 2/22/17.
//  Copyright © 2017 Sunil. All rights reserved.
//

#ifndef Library_hpp
#define Library_hpp

#include <iostream>

using namespace std;

namespace Utils {
    
    inline namespace V99 {
        int add(int, int);
    };
    
    namespace V98 {
        int add(int, int);
    };
};

#endif /* Library_hpp */
