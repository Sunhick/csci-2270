//
//  CommunicationNetwork.h
//  Assignment4
//
//  Created by Sunil on 2/11/17.
//  Copyright © 2017 Sunil. All rights reserved.
//

#ifndef CommunicationNetwork_h
#define CommunicationNetwork_h

#include <iostream>
#include <string>

#include "NetworkTypeTraits.h"
#include "NetworkIterator.h"

//class NetworkIterator;

class CommunicationNetwork : public NetworkTypeTraits<std::string> {
public:
    CommunicationNetwork();
    ~CommunicationNetwork();
    void addCity(std::string, std::string);
    void buildNetwork();
    void transmitMsg(char *); //this is like a string
    void printNetwork();
    NetworkIterator<std::string> begin() {
        return NetworkIterator<std::string>(this->head);
    }
    NetworkIterator<std::string> end() {
        return NetworkIterator<std::string>();
    }
    
    
private:
    City<std::string> *head;
    City<std::string> *tail;
};


#endif /* CommunicationNetwork_h */
