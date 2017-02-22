//
//  Length.hpp
//  literals
//
//  Created by Sunil on 2/21/17.
//  Copyright © 2017 Sunil. All rights reserved.
//

#ifndef Length_hpp
#define Length_hpp

#include <iostream>

//template<typename T> class Length;

enum Distance {
    Miles,
    Kilometers
};

template<typename T = float>
class Length {
private:
    T miles;
    static constexpr float mi2km = 1.609344;
    static constexpr float km2mi = 1/mi2km;
    
public:
    Length(T);
    Length(T, Distance);
    Length(const Length&);
    Length(Length&&);
    ~Length();
    
    Length<T> operator+(Length&);
    Length<T>&& operator+(Length&&);
    
    T getMiles() const noexcept(true);
    T getKilometers() const noexcept(true);
};

// include the template implementations
#include "Length.cpp"

#endif /* Length_hpp */
