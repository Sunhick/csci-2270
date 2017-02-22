//
//  Library.cpp
//  inline namespace : function versioning (libraries)
//
//  Created by Sunil on 2/22/17.
//  Copyright © 2017 Sunil. All rights reserved.
//

#include "Library.hpp"

namespace Utils {
    inline namespace V99 {
        int add(int a, int b) {
            cout << "log: " << a+b << endl;
            return a+b;
        }
    };
    
    namespace V98 {
        int add(int a, int b) {
            return a+b;
        }
    };
};
