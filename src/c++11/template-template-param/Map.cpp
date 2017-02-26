//
//  Map.cpp
//  template-template
//
//  Created by Sunil on 2/26/17.
//  Copyright © 2017 Sunil. All rights reserved.
//

#ifndef Map_cpp
#define Map_cpp

#include "Map.hpp"

template<typename Type>
Container<Type>::Container(int size) {
    array = new Type[size];
    this->size = size;
}

template<typename Type>
Container<Type>::~Container() {
    delete[] array;
}

template<typename Type>
Type& Container<Type>::operator[](int index) {
    return array[index];
}

template<typename KeyType, typename ValueType, template<typename> class Array>
Map<KeyType, ValueType, Array>::Map() {
    
}

template<typename KeyType, typename ValueType, template<typename> class Array>
Map<KeyType, ValueType, Array>::~Map() {
    
}

template<typename KeyType, typename ValueType, template<typename> class Array>
ValueType& Map<KeyType, ValueType, Array>::operator[](KeyType key) {
    return values[key];
}

#endif // Map_cpp
