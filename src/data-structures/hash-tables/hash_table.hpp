//
//  hash_table.hpp
//  test22
//
//  Created by Sunil on 4/25/17.
//  Copyright © 2017 Sunil. All rights reserved.
//

#ifndef hash_table_hpp
#define hash_table_hpp

#include <iostream>
#include <string>

using namespace std;

struct hash_element {
    string key;
    hash_element *previous;
    hash_element *next;
    
    hash_element() {
        key = "";
        previous = next = NULL;
    }
};


class hash_table {
private:
    static constexpr int tableSize = 100;
    hash_element table[tableSize];
    int hashSum(string, int);
    
public:
    void insert(string value);
};

#endif /* hash_table_hpp */
