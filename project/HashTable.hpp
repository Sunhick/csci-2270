//
//  HashTable.hpp
//  HashTables
//
//  Created by Sunil on 4/28/17.
//  Copyright © 2017 Sunil. All rights reserved.
//

#ifndef HashTable_hpp
#define HashTable_hpp

#include <iostream>

#include "PlayerInfo.hpp"

using namespace std;

class HashEntry {
public:
    PlayerInfo player;
    
    HashEntry(PlayerInfo value) : player(value) { };
    
    HashEntry(const HashEntry& other) {
        // copy ctor: memberwise copy
        std::memcpy(this, &other, sizeof(HashEntry));
    }
};

class HashTable {
private:
    HashEntry **table;
    int capacity;
    int size;
    
    unsigned int hashfunc(const char* str, unsigned int seed = 0);
    inline int getIndex(string key);
    
public:
    HashTable(int size = 1024);
    ~HashTable();
    
    void put(string key, PlayerInfo value);
    PlayerInfo* get(string key);
    void clear();
    void rehash();
};

#endif /* HashTable_hpp */
