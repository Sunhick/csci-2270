//
//  Length.inc
//  literals
//
//  Created by Sunil on 2/21/17.
//  Copyright © 2017 Sunil. All rights reserved.
//

// gaurd conditions are required here.
// since we are including the cpp file in the header.

#ifndef Length_cpp
#define Length_cpp

#include "Length.hpp"

template<typename T>
Length<T>::Length(T miles) {
    this->miles = miles;
}

template<typename T>
Length<T>::Length(T value, Distance type) {
    miles = type == Distance::Miles ? value : value * km2mi;
}

template<typename T>
Length<T>::Length(const Length& rhs) {
    miles = rhs.miles;
}

template<typename T>
Length<T>::Length(Length&& rhs) {
    miles = rhs.miles;
}

template<typename T>
Length<T>::~Length() {
    miles = 0;
}

template<typename T>
T Length<T>::getMiles() const noexcept(true) {
    return miles;
}

template<typename T>
T Length<T>::getKilometers() const noexcept(true) {
    return miles * mi2km;
}

template<typename T>
Length<T> Length<T>::operator+(Length& other) {
    return Length<T>(miles + other.miles);
}

template<typename T>
Length<T>&& Length<T>::operator+(Length&& other) {
    return std::move(Length<T>(miles + other.miles));
}

#endif /* Length_cpp */
