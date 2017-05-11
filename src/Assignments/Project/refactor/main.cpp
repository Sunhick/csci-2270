//
//  main.cpp
//  HashTables
//
//  Created by Sunil on 4/28/17.
//  Copyright © 2017 Sunil. All rights reserved.
//

#include <string>
#include <chrono>
#include <memory>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <iostream>

#include "HashTable.hpp"
#include "PlayerInfo.hpp"

using namespace std;

void die(string message) {
    cout << message << endl;
    exit(0);
}

void PopulateHashTable(string filename, std::shared_ptr<HashTable> map) {
    ifstream file(filename);
    
    // non-existant or corrupted file
    if(file.fail()) {
        die("Could not open file");
    }
    
    string line;
    
    string ignoreHeader;
    std::getline(file, ignoreHeader);
    
    // cout << ignoreHeader << endl;
    // std::setiosflags(ios::fixed);
    
    while(std::getline(file, line)) {
        auto playerInfo = PlayerInfo::ConstructFrom(line);
        
        // add playerInfo to the hash table.
        auto key = PlayerInfo::MakeKey(playerInfo);
        map->put(key, playerInfo);
    }
}

int getTableSize(string size) {
    char multiplier = ' ';
    float number;
    
    istringstream ss(size);
    ss >> number >> multiplier;
    
    switch (multiplier) {
        case 'k':
        case 'K':
            // Kilo
            number *= 1000;
            break;
            
        case ' ':
            break;
            
        default:
            cout << "Only K/k multiplier is supported!" << endl;
            break;
    }

    return number;
}

int main(int argc, const char * argv[]) {

    string dmenu =  "1. Query hash table\n"
                    "2. Quit program\n";
    
    string help = "usage: $executable [input file] [hashtable size]\n"
                  "example: $exe PlayerData.txt 5072";
    
    if (argc < 3) {
        cout << "Missing arguments to the program!" << endl;
        die(help);
    }
    
    int choice = 0;
    bool done = false;
    
    string filename {argv[1]};
    int hashSize = getTableSize(argv[2]);
    
    // create collision counter variables
    std::shared_ptr<CollisionCounter> linearProbeStats(new CollisionCounter("(linear probe)"));
    std::shared_ptr<CollisionCounter> chainingStats(new CollisionCounter("(chaining)"));
    
    // Let c++11 smart pointers do memory management for me.
    auto map = std::shared_ptr<HashTable>(
                    new HashTable(hashSize,
                                  std::unique_ptr<ChainingResolver>(new ChainingResolver(chainingStats)))
                );
    auto map2 = std::shared_ptr<HashTable>(
                    new HashTable(hashSize,
                                  std::unique_ptr<CollisionResolver>(new LinearProbingResolver(linearProbeStats)))
                );
    
    PopulateHashTable(filename, map);
    PopulateHashTable(filename, map2);
    
    cout << "Hash table size: " << hashSize << endl;
    cout << "Collisions using open addressing: " << linearProbeStats->addCollisions << endl;
    cout << "Collisions using chaining: " << chainingStats->addCollisions << endl;
    cout << "Search operations using chaining: " << chainingStats->lookupCollisions << endl;
    cout << "Search operations using open addressing: " << linearProbeStats->lookupCollisions << endl;
    
    linearProbeStats->resetCounters();
    chainingStats->resetCounters();
    
    do {
        cout << dmenu;
        cin >> choice;
        
        // flush the newlines and other characters
        cin.clear();
        cin.ignore();
        
        switch (choice) {
            case 1:
            {
                string firstName, lastName;
                
                cout << "Enter first name: " << endl;
                std::getline(cin, firstName);
                cout << "Enter last name: " << endl;
                std::getline(cin, lastName);
                
                auto key = PlayerInfo::MakeKey(firstName, lastName);
                
                // look up with chaining
                {
                    auto found = map->get(key);

                    cout << endl << "Search operations using chaining: " << chainingStats->lookupCollisions << endl;
                    found->show();
                    chainingStats->resetCounters();
                }
                
                // look up with linear probing
                {
                    auto found = map2->get(key);
                    
                    cout << "Search operations using open addressing: " << linearProbeStats->lookupCollisions << endl;
                    found->show();
                    linearProbeStats->resetCounters();
                }
                
                break;
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
    return 0;
}
