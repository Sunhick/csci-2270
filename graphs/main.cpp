//
//  main.cpp
//  zombies
//
//  Created by Sunil on 4/17/17.
//  Copyright © 2017 Sunil. All rights reserved.
//

#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <iostream>
#include <memory>

#include "Graph.h"

using namespace std;

void die(string message) {
    cout << message << endl;
    exit(0);
}

unique_ptr<Graph<string>> PopulateNetwork(string filename) {
    unique_ptr<Graph<string>> network(new Graph<string>());
    
    ifstream file(filename);
    
    // non-existant or corrupted file
    if(file.fail()) {
        die("Could not open file");
    }
    
    string line;
    vector<string> cities;
    
    while(std::getline(file, line)) {
        stringstream lineStream(line);
        
        string city, id;
        std::getline(lineStream, id, ',');
        
        if (id == "cities") {
            while (std::getline(lineStream, city, ',')) {
                // collect all cities. Add it as a vertex.
                cities.push_back(city);
                network->addVertex(city);
            }
            continue;
        }
        
        // must be an edge
        auto fromCity = id;
        int dist = 0;
        int index = 0;
        
        while (lineStream >> dist) {
            
            // ignore the char comma from the input stream.
            char ignoreComma;
            lineStream >> ignoreComma;
            
            // add the edges
            auto toCity = cities[index];
            network->addEdge(fromCity, toCity, dist);
            index++;
        }
        
    }
    
    return std::move(network);
}

int main(int argc, const char * argv[]) {
    
    string dmenu =  "======Main Menu======\n"
                    "1. Print vertices\n"
                    "2. Find districts\n"
                    "3. Find shortest path\n"
                    "4. Quit\n";
    
    if (argc < 2){
        die("Missing input file!");
    }
    
    int choice = 0;
    bool done = false;
    
    string filename(argv[1]);
    auto network = PopulateNetwork(filename);
    
    do {
        cout << dmenu;
        cin >> choice;
        
        // flush the newlines and other characters
        cin.clear();
        cin.ignore();
        
        switch (choice) {
            case 1:
            {
                network->displayEdges();
                break;
            }
                
            case 2:
            {
                break;
            }
                
            case 3:
            {
                break;
            }
                
            case 4:
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
