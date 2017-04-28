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
        stringstream lineStream(line);
        
        // Format of the line:
        // yearID : int
        // teamID : int
        // leagueID : int
        // playerID : int
        // salary : float
        // firstName : string
        // lastName : string
        // birthYear : string
        // birthCountry : string
        // weight : float
        // height : float
        // bats : int
        // throws : int
        int yearId;
        char bats, throws;
        float salary, weight, height;
        string teamId, playerId, leagueId, firstName, lastName, birthYear, birthCountry;
        char ignoreComma;
        
        lineStream >> yearId;       lineStream >> ignoreComma;
        // lineStream >> teamId;       lineStream >> ignoreComma;
        std::getline(lineStream, teamId, ',');
        // lineStream >> leagueId;     lineStream >> ignoreComma;
        std::getline(lineStream, leagueId, ',');
        // lineStream >> playerId;     lineStream >> ignoreComma;
        std::getline(lineStream, playerId, ',');
        lineStream >> salary;       lineStream >> ignoreComma;
        // lineStream >> firstName;    lineStream >> ignoreComma;
        std::getline(lineStream, firstName, ',');
        // lineStream >> lastName;     lineStream >> ignoreComma;
        std::getline(lineStream, lastName, ',');
        // lineStream >> birthYear;    lineStream >> ignoreComma;
        std::getline(lineStream, birthYear, ',');
        // lineStream >> birthCountry; lineStream >> ignoreComma;
        std::getline(lineStream, birthCountry, ',');
        lineStream >> weight;       lineStream >> ignoreComma;
        lineStream >> height;       lineStream >> ignoreComma;
        lineStream >> bats;         lineStream >> ignoreComma;
        lineStream >> throws;
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
