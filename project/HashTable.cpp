//
//  HashTable.cpp
//  HashTables
//
//  Created by Sunil on 4/28/17.
//  Copyright © 2017 Sunil. All rights reserved.
//

#include "HashTable.hpp"

HashTable::HashTable(int capacity) {
    this->capacity = capacity;
    // construct zero initialized hash table of size
    table = new HashEntry *[capacity];
    size = 0;
}

HashTable::~HashTable() {
    
}

unsigned int HashTable::hashfunc(const char* str, unsigned int seed) {
    // Based on work of Paul Larson & George V Reilly from Microsoft.
    // Simple and yet fast so that we get O(1) for hash function look ups
    unsigned int hash = seed;
    while (*str) hash = hash * 101  +  *str++;
    return hash;
}



void HashTable::put(string key, PlayerInfo value) {
    auto index = getIndex(key);
    
    table[index] = new HashEntry(value);
    size++;
}

PlayerInfo* HashTable::get(string key) {
    auto index = getIndex(key);
    return &table[index]->player;
}

void HashTable::clear() {
    
}

void HashTable::rehash() {
    throw runtime_error("Not implemented!");
}

inline int HashTable::getIndex(string key) {
    auto hash = hashfunc(key.c_str());
    // Ensure we are not out of bounds of the hash table size
    return hash % capacity;
}
