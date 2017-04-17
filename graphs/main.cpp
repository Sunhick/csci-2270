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

#include "Graph.h"

using namespace std;

void die(string message) {
    cout << message << endl;
    exit(0);
}

Graph<string>&& PopulateNetwork(string filename) {
    Graph<string> network;
    
    ifstream file(filename);
    
    // non-existant or corrupted file
    if(file.fail()) {
        die("Could not open file");
    }
    
    string line;
    
    while(std::getline(file, line)) {
        stringstream lineStream(line);
        
        
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

//#include <iostream>
//#include <vector>
//#include "Graph.h"
//
//using namespace std;
//
//
//int main()
//{
//    Graph<string> g;
//    g.addVertex("Boulder");
//    g.addVertex("Denver");
//    g.addVertex("New Mexico");
//    g.addVertex("Texas");
//    g.addVertex("New Orleans");
//    //edge written to be undirected
//    g.addEdge("Boulder", "Denver", 30);
//    g.addEdge("Boulder", "New Mexico", 200);
//    g.addEdge("Boulder", "Texas", 500);
//    g.addEdge("Denver", "Texas", 300);
//    g.addEdge("Texas", "New Orleans", 500);
//    g.displayEdges();
//
//    Graph<int> g2;
//    g2.addVertex(5);
//    g2.addVertex(6);
//    g2.addVertex(7);
//    g2.addVertex(8);
//    g2.addEdge(5,6,30);
//    g2.addEdge(5,7,300);
//    g2.addEdge(7,8,10);
//    g2.displayEdges();
//    
//    
//    return 0;
//}
