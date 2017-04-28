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
    HashEntry() { };
};

class HashTable {
private:
    HashEntry **table;
    int size;
    
    int hashFunction();
    
public:
    HashTable(int size = 1024);
    ~HashTable();
};

#endif /* HashTable_hpp */
