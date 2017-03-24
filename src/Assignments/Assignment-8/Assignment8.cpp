//
//  main.cpp
//  Assignment-8
//
//  Created by Sunil on 3/11/17.
//  Copyright © 2017 Sunil. All rights reserved.
//

#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <iostream>

#include "MovieTree.h"

using namespace std;

void die(string message) {
    cout << message << endl;
    exit(0);
}

void PopulateCatalog(MovieTree* catalog, string filename) {
    ifstream file(filename);
    
    // non-existant or corrupted file
    if(file.fail()) {
        die("Check if file exists!");
    }
    
    int ranking, releaseYear, quantity;
    string title ,word, line;

    while(std::getline(file, line)) {
        stringstream lineStream(line);
        
        // format of Assignment8Movie.txt:
        // ranking(integer), title(string), releaseYear(integer), quantity(integer)
        std::getline(lineStream, word, ',');
        ranking = atoi(word.c_str());
        
        std::getline(lineStream, word, ',');
        title = word;
        
        std::getline(lineStream, word, ',');
        releaseYear = atoi(word.c_str());
        
        std::getline(lineStream, word);
        quantity = atoi(word.c_str());
        
        // add to movie catalog.
        catalog->addMovieNode(ranking, title, releaseYear, quantity);
    }
}

int main(int argc, const char * argv[]) {

    string dmenu =  "======Main Menu======\n"
                    "1. Find a movie\n"
                    "2. Rent a movie\n"
                    "3. Print the inventory\n"
                    "4. Delete a movie\n"
                    "5. Count the movies\n"
                    "6. Quit\n";
    
    if (argc < 2){
        die("Missing movie collection file!");
    }
    
    int choice = 0;
    bool done = false;
    MovieTree catalog;
    
    string filename(argv[1]);
    PopulateCatalog(&catalog, filename);
    
    do {
        cout << dmenu;
        cin >> choice;
        
        // flush the newlines and other characters
        cin.clear();
        cin.ignore();
        
        switch (choice) {
            case 1:
            {
                string title;
                cout << "Enter title:" << endl;
                std::getline(cin, title);
                catalog.findMovie(title);
                break;
            }
                
            case 2:
            {
                string title;
                cout << "Enter title:" << endl;
                std::getline(cin, title);
                catalog.rentMovie(title);
                break;
            }
                
            case 3:
            {
                catalog.printMovieInventory();
                break;
            }
                
            case 4:
            {
                string title;
                cout << "Enter title:" << endl;
                std::getline(cin, title);
                catalog.deleteMovieNode(title);
                break;
            }
                
            case 5:
            {
                cout << "Tree contains: " << catalog.countMovieNodes() << " movies." << endl;
                break;
            }
                
            case 6:
            default:
            {
                done = true;
                break;
            }
        }
        
    } while(!done);
    
    cout << "Goodbye!" << endl;
    return 0;
}
