//
//  base.hpp
//  casting
//
//  Created by Sunil on 2/21/17.
//  Copyright © 2017 Sunil. All rights reserved.
//

#ifndef base_hpp
#define base_hpp

#include <string>

using namespace std;

class base {
private:
    string name;

public:
    base();
    base(string n);
    ~base();
    void virtual print();
};

#endif /* base_hpp */
