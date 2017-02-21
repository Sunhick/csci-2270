//
//  main.cpp
//  Assignment4
//
//  Created by Sunil on 2/11/17.
//  Copyright © 2017 Sunil. All rights reserved.
//

#include <iostream>
#include <string>
#include <cstring>

#include "CommunicationNetwork.h"

using namespace std;

template<>
std::string DefaultValues<std::string>::values[10] = {"Los Angeles", "Phoenix", "Denver", \
    "Dallas", "St. Louis", "Chicago", "Atlanta", "Washington, D.C.", "New York", "Boston"};

template<>
std::string DefaultValues<std::string>::dval = "";

template<>
int DefaultValues<int>::values[10] = {10,9,8,7,6,5,4,3,2,1};

template<>
int DefaultValues<int>::dval = -1;

template<>
double DefaultValues<double>::values[10] = {10.9,9.9,8.9,7.9,6.9,5.9,4.9,3.9,2.9,1.9};

template<>
double DefaultValues<double>::dval = -1.0;

int main(int argc, const char * argv[]) {
    // Automatic string concat
    std::string dmenu = "======Main Menu======\n"
                        "1. Build Network\n"
                        "2. Print Network Path\n"
                        "3. Transmit Message Coast-To-Coast\n"
                        "4. Add City\n"
                        "5. Quit\n";
    
    CommunicationNetwork<int> intNets;
    intNets.buildNetwork();
    intNets.printNetwork();
    
    CommunicationNetwork<double> dNets;
    dNets.buildNetwork();
    dNets.printNetwork();
    
    cout << dmenu;
    
    CommunicationNetwork<std::string> comNet;
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
