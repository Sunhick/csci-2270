//
//  main.cpp
//  Assignment4
//
//  Created by Sunil on 2/11/17.
//  Copyright © 2017 Sunil. All rights reserved.
//

#include <iostream>
#include <string>

#include "CommunicationNetwork.h"

using namespace std;

int main(int argc, const char * argv[]) {
    
    // Automatic string concat
    std::string dmenu = "======Main Menu======\n"
                        "1. Build Network\n"
                        "2. Print Network Path\n"
                        "3. Trasmit message Coast-To-Coast\n"
                        "4. Add City\n"
                        "5. Quit\n";
    
    cout << dmenu;
    
    CommunicationNetwork comNet;
    int option;
    bool exit = false;
    
    while(std::cin >> option) {
        switch (option) {
            case 1:
            {
                comNet.buildNetwork();
                break;
            }
            
            case 2:
            {
                comNet.printNetwork();
                break;
            }
                
            case 3:
            {
                cin.ignore();
                std::string line;
                std::getline(std::cin, line);
                char *msg = new char[line.length()];
                strcpy(msg, line.c_str());
                comNet.transmitMsg(msg);
                break;
            }
                
            case 4:
            {
                cin.ignore();
                std::string city, following;
                cout << "City name:";
                std::getline(std::cin, city);
                cout << "Following City:";
                std::getline(std::cin, following);
                
                comNet.addCity(city, following);
                break;
            }
                
            case 5:
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
    
    for(auto i : comNet) {
        cout << i << endl;
    }
    
    return 0;
}
