//
//  HashTable.cpp
//  HashTables
//
//  Created by Sunil on 4/28/17.
//  Copyright © 2017 Sunil. All rights reserved.
//

#include "HashTable.hpp"

HashTable::HashTable(int capacity, CollisionResolver* resolverStrategy)
    : capacity(capacity), size(0) {
    // construct zero initialized hash table of size
    table = new HashEntry *[capacity];
    this->resolverStrategy = resolverStrategy;
}

HashTable::~HashTable() {
    clear();
    delete resolverStrategy;
    delete table;
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
    
    auto collision = table[index];
    
    if (!collision) table[index] = new HashEntry(value);
    else resolverStrategy->add(table, new HashEntry(value), index);
    
    size++;
}

PlayerInfo* HashTable::get(string key) {
    auto index = getIndex(key);
    
    auto found = table[index];
    if (!found) return nullptr;
    
    return resolverStrategy->get(table, key, index);
}

void HashTable::clear() {
    if (!table) {
        return;
    }
    
    auto tsize = capacity;
    while (tsize-- > 0) {
        auto entry = table[tsize];
        if (!entry) continue;
        
        // Delete the record. Call resolver because we
        // don't know the internal of how collision is resolved.
        resolverStrategy->Delete(entry);
    }
}

void HashTable::rehash() {
    throw runtime_error("Not implemented!");
}

inline int HashTable::getIndex(string key) {
    auto hash = hashfunc(key.c_str());
    // Ensure we are not out of bounds of the hash table size
    return hash % capacity;
}
