//
//  NetworkTypeTraits.h
//  Assignment4
//
//  Created by Sunil on 2/11/17.
//  Copyright © 2017 Sunil. All rights reserved.
//

#ifndef NetworkTypeTraits_h
#define NetworkTypeTraits_h

#include <string>

template<typename T>
struct City {
    T cityName;
    std::string message;
    City *next;
    
    using v_type = T;
    
    City(){ }; // default constructor
    
    City(T initName, City *initNext, std::string initMessage)
    {
        cityName = initName;
        next = initNext;
        message = initMessage;
    }
};

template<typename T>
class NetworkTypeTraits {
public:
    using value_type = typename City<T>::v_type;
    using elem_type = City<T>;
    using ref_type = City<T>&;
    using ptr_type = City<T>*;
    using const_ptr_type = const City<T>*;
    using iterator_category = std::forward_iterator_tag;

};
#endif /* NetworkTypeTraits_h */
