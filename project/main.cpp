//
//  main.cpp
//  HashTables
//
//  Created by Sunil on 4/28/17.
//  Copyright © 2017 Sunil. All rights reserved.
//

#include <string>
#include <chrono>
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

void PopulateHashTable(string filename, HashTable* map) {
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
    int hashSize = stoi(argv[2]);
    
    std::chrono::time_point<std::chrono::system_clock> start, end;
    
    // create collision counter variables
    CollisionCounter linearProbeStats("(linear probe)");
    CollisionCounter chainingStats("(chaining)");
    
    HashTable* map = new HashTable(hashSize, new ChainingResolver(&chainingStats));
    HashTable* map2 = new HashTable(hashSize, new LinearProbingResolver(&linearProbeStats));
    
    // time adding to hash table with chaining
    start = std::chrono::system_clock::now();
    PopulateHashTable(filename, map);
    end = std::chrono::system_clock::now();
    
    chainingStats.showAddCollisions();
    
    // time adding to hash table with chaining
    std::chrono::duration<double> elapsed_seconds = end - start;
    std::cout << "(chaining) Populate table elapsed time: " << elapsed_seconds.count() << "s\n";
    
    // time adding to hash table with linear probing
    start = std::chrono::system_clock::now();
    PopulateHashTable(filename, map2);
    end = std::chrono::system_clock::now();
    
    linearProbeStats.showAddCollisions();
    
    elapsed_seconds = end - start;
    std::cout << "(linear probe) Populate table elapsed time: " << elapsed_seconds.count() << "s\n";

    linearProbeStats.resetCounters();
    chainingStats.resetCounters();
    
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
                    start = std::chrono::system_clock::now();
                    auto found = map->get(key);
                    end = std::chrono::system_clock::now();
                    elapsed_seconds = end - start;
                    
                    cout << "(chaining) lookup time: " << elapsed_seconds.count() << "s\n";
                    if (found) found->show();
                    else cout << "Record not found!" << endl;
                    
                    chainingStats.showlookupCollisions();
                    chainingStats.resetCounters();
                }
                
                // look up with linear probing
                {
                    start = std::chrono::system_clock::now();
                    auto found = map2->get(key);
                    end = std::chrono::system_clock::now();
                    elapsed_seconds = end - start;
                    
                    cout << "(linear probe) lookup time: " << elapsed_seconds.count() << "s\n";
                    if (found) found->show();
                    else cout << "Record not found!" << endl;
                    
                    linearProbeStats.showlookupCollisions();
                    linearProbeStats.resetCounters();
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
    delete map;
    delete map2;
    return 0;
}
