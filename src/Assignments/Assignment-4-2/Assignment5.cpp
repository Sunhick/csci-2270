//
//  main.cpp
//  Assignment4-2
//
//  Created by Sunil on 2/15/17.
//  Copyright © 2017 Sunil. All rights reserved.
//
#include <iostream>
#include <string>
#include <cstring>

#include "CommunicationNetwork.h"

using namespace std;

int main(int argc, const char * argv[]) {
    
    // Automatic string concat
    std::string dmenu = "======Main Menu======\n"
                        "1. Build Network\n"
                        "2. Print Network Path\n"
                        "3. Transmit Message Coast-To-Coast-To-Coast\n"
                        "4. Add City\n"
                        "5. Delete City\n"
                        "6. Clear Network\n"
                        "7. Quit\n";
    
    cout << dmenu;
    
    CommunicationNetwork comNet;
    int option;
    bool exit = false;
    
    while(std::cin >> option) {
        
        // flush the newlines and other characters
        cin.clear();
        cin.ignore();
        
        switch (option) {
            case 1:
            {
                comNet.buildNetwork();
                comNet.printNetwork();
                break;
            }
                
            case 2:
            {
                comNet.printNetwork();
                break;
            }
                
            case 3:
            {
                char *filename = new char[strlen(argv[1])];
                strcpy(filename, argv[1]);
                comNet.transmitMsg(filename);
                delete[] filename;
                break;
            }
                
            case 4:
            {
                std::string cityNew, cityPrevious;
                cout << "Enter a city name: " << endl;
                std::getline(cin,cityNew);
                cout << "Enter a previous city name: " << endl;
                std::getline(cin,cityPrevious);
                comNet.addCity(cityNew, cityPrevious);
                break;
            }
                
            case 5:
            {
                cout << "Enter a city name: " << endl;
                std::string removeCity;
                std::getline(cin, removeCity);
                comNet.deleteCity(removeCity);
                break;
            }
                
            case 6:
            {
                comNet.deleteNetwork();
                break;
            }
                
            case 7:
            {
                exit = true;
                break;
            }
        }
        
        if(exit) {
            // break out of while loop
            break;
        }
        
        cout << dmenu;
    }
    
    cout << "Goodbye!" << endl;
    return 0;
}
