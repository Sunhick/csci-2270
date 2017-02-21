//
//  derived.hpp
//  casting
//
//  Created by Sunil on 2/21/17.
//  Copyright © 2017 Sunil. All rights reserved.
//

#ifndef derived_hpp
#define derived_hpp

#include <string>
#include "base.hpp"

class derived : public base {
private:
    string name;
    
public:
    derived(string n);
    ~derived();
    void virtual print() override;
    void extraPrint();
};

#endif /* derived_hpp */
