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
#include "CollisionResolver.hpp"

using namespace std;

class HashEntry {
public:
    PlayerInfo player;
    
    HashEntry(PlayerInfo value)
        : player(value), next(nullptr), previous(nullptr)
    { };
    
    HashEntry(const HashEntry& other) {
        // copy ctor: memberwise copy
        std::memcpy(this, &other, sizeof(HashEntry));
    }
    
    HashEntry* next;
    HashEntry* previous;
};

class HashTable {
private:
    HashEntry **table;
    CollisionResolver *resolverStrategy;
    int capacity;
    int size;
    
    unsigned int hashfunc(const char* str, unsigned int seed = 0);
    inline int getIndex(string key);
    
    // Resolvers are friend classes 
    friend class LinearProbingResolver;
    friend class ChainingResolver;
    
public:
    HashTable(int size = 1024, CollisionResolver* resolverStrategy = nullptr);
    ~HashTable();
    
    void put(string key, PlayerInfo value);
    PlayerInfo* get(string key);
    void clear();
    void rehash();
};

#endif /* HashTable_hpp */
