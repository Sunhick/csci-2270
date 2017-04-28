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

#endif /* CollisionResolver_hpp */
