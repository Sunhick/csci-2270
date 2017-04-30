//
//  CollisionResolver.cpp
//  HashTables
//
//  Created by Sunil on 4/28/17.
//  Copyright © 2017 Sunil. All rights reserved.
//

#include <iostream>

#include "HashTable.hpp"
#include "PlayerInfo.hpp"
#include "CollisionResolver.hpp"

ChainingResolver::ChainingResolver(CollisionCounter* counter)
    : counter(counter) {
    
}

PlayerInfo* ChainingResolver::get(HashTable* map, string key, int index) {
    auto entry = map->table[index];
    while (entry) {
        if (entry->player.key() == key) {
            return &entry->player;
        }
        
        entry = entry->next;
    
        // track the look up collisions
        if (counter) counter->lookupCollisions++;
    }
    
    return nullptr;
}

void ChainingResolver::add(HashTable* map, HashEntry* entry, int index) {
    auto collidedEntry = map->table[index];
    while (!collidedEntry->player.areSame(entry->player) && collidedEntry->next) {
        collidedEntry = collidedEntry->next;
        
        // track the add collisions
        if (counter) counter->addCollisions++;
    }
    
    // match at the last entry ?
    if (collidedEntry->player.areSame(entry->player)) {
        collidedEntry->player.addMoreInfo(entry->player);
    } else {
        // no match found. just add it at the end of list.
        collidedEntry->next = entry;
    }
}

void ChainingResolver::Delete(HashEntry* entry) {
    auto prev = entry;
    if (entry) {
        entry = entry->next;
        delete prev;
        prev = entry;
    }
}

ChainingResolver::~ChainingResolver() {
    // chaining resolver doesn't own collision counter.
    // so don't free it. just lose the ref.
    counter = nullptr;
}
