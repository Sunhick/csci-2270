//
//  CollisionResolver.cpp
//  HashTables
//
//  Created by Sunil on 4/28/17.
//  Copyright © 2017 Sunil. All rights reserved.
//

#ifndef CollisionResolver_hpp
#define CollisionResolver_hpp

#include <string>

using namespace std;

class PlayerInfo;
class HashTable;
class HashEntry;

class CollisionResolver {
public:
    virtual void add(HashEntry**& table, HashEntry* entry, int index) = 0;
    virtual PlayerInfo* get(HashEntry**& table, string key, int index) = 0;
    virtual void Delete(HashEntry* entry) = 0;
    
    virtual ~CollisionResolver() { }
};

// open addressing (using linear probing)
class LinearProbingResolver : public CollisionResolver {
public:
    virtual void add(HashEntry**& table, HashEntry* entry, int index) override;
    virtual PlayerInfo* get(HashEntry**& table, string key, int index) override;
    virtual void Delete(HashEntry* entry) override;
    
    virtual ~LinearProbingResolver();
};

// collsion resolution using chaining
class ChainingResolver : public CollisionResolver {
public:
    virtual void add(HashEntry**& table, HashEntry* entry, int index) override;
    virtual PlayerInfo* get(HashEntry**& table, string key, int index) override;
    virtual void Delete(HashEntry* entry) override;
    
    virtual ~ChainingResolver();
};

#endif /* CollisionResolver_hpp */
