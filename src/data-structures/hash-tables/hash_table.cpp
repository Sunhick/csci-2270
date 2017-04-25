//
//  hash_table.cpp
//  test22
//
//  Created by Sunil on 4/25/17.
//  Copyright © 2017 Sunil. All rights reserved.
//

#include "hash_table.hpp"

int hash_table::hashSum(string key, int size) {
    auto sum = 0;
    
    for (int i = 0; i < key.length(); i++) {
        sum = sum + key[i];
    }
    
    sum = sum % size;
    return sum;
}

void hash_table::insert(string value) {
    auto index = hashSum(value, tableSize); // hash is calculated
    hash_element* hashElement = new hash_element;
    hashElement->key = value; //set properties of new record hashElement.next = NULL
    hashElement->previous = NULL;
    
    if (table[index].next == NULL) {
        hashElement->previous = &table[index];
        table[index].next = hashElement;
    }
    else {
        auto tmp = table[index].next;
        while(tmp != NULL) {
            if(tmp->key == value) {
                cout  << "duplicate";
                return;
            }
            tmp = tmp->next;
        }
        tmp = table[index].next;
        
        while(tmp->next != NULL && hashElement->key > tmp->key) {
            tmp = tmp->next;
        }
        
        if (hashElement->key > tmp->key) {
            // insert to the right of tmp
            hashElement->next = tmp->next;
            tmp->next = hashElement;
            hashElement->previous = tmp;
            if (hashElement->next != NULL)
                hashElement->next->previous = hashElement;
        } else {
            // insert to the left of tmp
            hashElement->next = tmp;
            hashElement->previous = tmp->previous;
            tmp->previous = hashElement;
            hashElement->previous->next = hashElement;
        }
    }
}
