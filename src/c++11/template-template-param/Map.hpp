//
//  Map.hpp
//  template-template
//
//  Created by Sunil on 2/26/17.
//  Copyright © 2017 Sunil. All rights reserved.
//

#ifndef Map_hpp
#define Map_hpp

#include <iostream>

// template for container
template<typename Type>
class Container {
private:
    Type* array;
    int size;
public:
    Container(int=10);
    ~Container();
    
    Type& operator[](int);
};

// construct a Map
template<typename KeyType, typename ValueType, template<typename> class Array>
class Map {
private:
    Array<KeyType> keys;
    Array<ValueType> values;
public:
    Map();
    ~Map();
    
    ValueType& operator[](KeyType);
};

#include "Map.cpp"

#endif /* Map_hpp */
