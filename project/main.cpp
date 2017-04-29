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
    
    HashTable* map = new HashTable(hashSize, new ChainingResolver);
    HashTable* map2 = new HashTable(hashSize, new LinearProbingResolver);
    
    // read the file and populate the map, map2
    PopulateHashTable(filename, map);
    PopulateHashTable(filename, map2);

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
                
                auto found = map->get(PlayerInfo::MakeKey(firstName, lastName));
                if (found) {
                    auto playerInfo = *found;
                    cout << playerInfo.yearId << "," << playerInfo.teamId << "," << playerInfo.leagueId << ","
                    << playerInfo.playerId << "," << playerInfo.salary << "," << playerInfo.firstName << ","
                    << playerInfo.lastName << "," << playerInfo.birthYear << "," << playerInfo.birthCountry << ","
                    << playerInfo.weight << "," << playerInfo.height << "," << playerInfo.bats << ","
                    << playerInfo.throws << endl;
                } else {
                    cout << "Record not found!" << endl;
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
    return 0;
}
