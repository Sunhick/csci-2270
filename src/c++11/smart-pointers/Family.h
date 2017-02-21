//
//  Family.hpp
//  SmartPointers
//
//  Created by Sunil on 2/20/17.
//  Copyright © 2017 Sunil. All rights reserved.
//

#ifndef Family_h
#define Family_h

#include <iostream>
#include <cstring>
#include <memory>

namespace Family {
    // forward declaration
    class Wife;
    
    class Husband {
    private:
        std::string name;
        std::weak_ptr<Wife> wife;

    public:
        Husband(std::string name);
        Husband(std::string name, std::shared_ptr<Wife> wife);
        ~Husband();
        
        void PrintCouples();
        void SetWife(std::shared_ptr<Wife> wife);
        std::string Name();
    };
    
    class Wife {
    private:
        std::string name;
        std::weak_ptr<Husband> husband;
        
    public:
        Wife(std::string name);
        Wife(std::string name, std::shared_ptr<Husband> husband);
        ~Wife();
        
        void PrintCouples();
        void SetHusband(std::shared_ptr<Husband> husband);
        std::string Name();
    };
}

#endif /* Family_h */
