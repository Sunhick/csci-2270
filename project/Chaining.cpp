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

PlayerInfo* ChainingResolver::get(HashEntry**& table, string key, int index) {
    cout << "chaining get for: " << key << endl;
    auto entry = table[index];
    while (entry) {
        if (entry->player.key() == key) return &entry->player;
        entry = entry->next;
    }
    
    return nullptr;
}

void ChainingResolver::add(HashEntry**& table, HashEntry* entry, int index) {
    cout << "chaining add for: " << entry->player.firstName << entry->player.lastName << endl;
    auto collidedEntry = table[index];
    while (collidedEntry->next) {
        collidedEntry = collidedEntry->next;
    }
    
    collidedEntry->next = entry;
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
    
}
