//
//  HashTable.cpp
//  HashTables
//
//  Created by Sunil on 4/28/17.
//  Copyright © 2017 Sunil. All rights reserved.
//

#include "HashTable.hpp"

HashTable::HashTable(int size) {
    this->size = size;
    // construct zero initialized hash table of size
    table = new HashEntry *[size];
}

HashTable::~HashTable() {
    
}

int HashTable::hashFunction() {
    return 0;
}
