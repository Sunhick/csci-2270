//
//  main.cpp
//  HashTables
//
//  Created by Sunil on 4/28/17.
//  Copyright © 2017 Sunil. All rights reserved.
//

#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <iostream>

#include "HashTable.hpp"
#include "Utilities.hpp"

using namespace std;

void die(string message) {
    cout << message << endl;
    exit(0);
}

void PopulateHashTable(string filename, HashTable* map) {
    ifstream file(filename);
    
    // non-existant or corrupted file
    if(file.fail()) {
        die("Could not open file");
    }
    
    string line;
    
    string ignoreHeader;
    std::getline(file, ignoreHeader);
    
    while(std::getline(file, line)) {
        auto playerInfo = Utilities::ConstructFrom(line);
        cout << "haha" << endl;
    }
}

int main(int argc, const char * argv[]) {
    
    string dmenu =  "1. Query hash table\n"
                    "2. Quit program\n";
    
    if (argc < 2) die("Missing input file!");
    
    int choice = 0;
    bool done = false;
    
    string filename(argv[1]);
    HashTable* map = new HashTable;
    
    // read the file and populate the map
    PopulateHashTable(filename, map);
    
    do {
        cout << dmenu;
        cin >> choice;
        
        // flush the newlines and other characters
        cin.clear();
        cin.ignore();
        
        switch (choice) {
            case 1:
            {
            }
                
            case 2:
            {
                done = true;
                break;
            }
            
            default:
            {
                // ignore unrecognized input.
                // and let program continue.
            }
        }
        
    } while(!done);
    
    cout << "Goodbye!" << endl;
    delete map;
    return 0;
}
