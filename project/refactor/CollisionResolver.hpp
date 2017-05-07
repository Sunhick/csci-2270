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

#include "CollisionCounter.hpp"

using namespace std;

// forward declaration to avoid cyclic reference
class PlayerInfo;
class HashTable;
class HashEntry;

// base class for all type of collision resolvers.
class CollisionResolver {
public:
    virtual void add(HashTable* map, HashEntry* entry, int index) = 0;
    virtual PlayerInfo get(HashTable* map, string key, int index) = 0;
    virtual void Delete(HashEntry* entry) = 0;
    
    virtual ~CollisionResolver() { }
};

// open addressing (using linear probing)
class LinearProbingResolver : public CollisionResolver {
private:
    CollisionCounter* counter;
    
public:
    LinearProbingResolver(CollisionCounter* counter = nullptr);
    
    virtual void add(HashTable* map, HashEntry* entry, int index) override;
    virtual PlayerInfo get(HashTable* map, string key, int index) override;
    virtual void Delete(HashEntry* entry) override;
    
    virtual ~LinearProbingResolver();
};

// collsion resolution using chaining
class ChainingResolver : public CollisionResolver {
private:
    CollisionCounter* counter;
    
public:
    ChainingResolver(CollisionCounter* counter = nullptr);
    
    virtual void add(HashTable* map, HashEntry* entry, int index) override;
    virtual PlayerInfo get(HashTable* map, string key, int index) override;
    virtual void Delete(HashEntry* entry) override;
    
    virtual ~ChainingResolver();
};

#endif /* CollisionResolver_hpp */
