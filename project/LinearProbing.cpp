//
//  LinearProbing.cpp
//  HashTables
//
//  Created by Sunil on 4/29/17.
//  Copyright © 2017 Sunil. All rights reserved.
//

#include "HashTable.hpp"
#include "CollisionResolver.hpp"

void LinearProbingResolver::add(HashTable* map, HashEntry* entry, int index) {
    // collision. look for a new slot by linear probing.
    int begin = 0;
    auto capacity = map->capacity;
    auto key = entry->player.key();
    
    while (begin++ < capacity) {
        // new entry
        if (!map->table[index]) {
            map->table[index] = entry;
            return;
        }
        
        // update the existing entry
        if (map->table[index]->player.areSame(entry->player)) {
            map->table[index]->player.addMoreInfo(entry->player);
            return;
        }
        
        index = (index+1) % capacity;
    }
    
    cout << "(linear probe): Unable to find a spot to add value!" << endl;
}

PlayerInfo* LinearProbingResolver::get(HashTable* map, string key, int index){
    auto begin = 0;
    auto capacity = map->capacity;
    
    while (begin++ < capacity) {
        if (map->table[index]->player.key() == key) return &map->table[index]->player;
        index = (index+1) % capacity;
    }
    
    return nullptr;
}

void LinearProbingResolver::Delete(HashEntry* entry) {
    delete entry;
}

LinearProbingResolver::~LinearProbingResolver() {
    
}
