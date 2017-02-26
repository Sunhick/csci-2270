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

#include <iostream>

using namespace std;

template<typename Type>
Container<Type>::Container(int size) {
    array = new Type[size];
    this->size = size;
}

template<typename Type>
Container<Type>::~Container() {
    // delete[] array;
    // cout << "deleted " << typeid(Type).name() << endl;
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
    int index = 0;
    auto it = std::find_if(&keys[0], &keys[0]+size, [&key, &index](KeyType ckey) {
        index++;
        return ckey == key;
    });
    
    if(it == &keys[0]+size) {
        // throw "key not found";
        keys[count] = key;
        return values[count++];
    }
    
    // found
    return values[index-1];
}

#endif // Map_cpp
