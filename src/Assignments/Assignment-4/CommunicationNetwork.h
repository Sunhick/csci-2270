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

struct City{
    std::string cityName;
    std::string message;
    City *next;
    
    City(){}; // default constructor
    
    City(std::string initName, City *initNext, std::string initMessage)
    {
        cityName = initName;
        next = initNext;
        message = initMessage;
    }
};

class CommunicationNetwork
{
public:
    CommunicationNetwork();
    ~CommunicationNetwork();
    void addCity(std::string, std::string);
    void buildNetwork();
    void transmitMsg(char *); //this is like a string
    void printNetwork();
protected:
private:
    City *head;
    City *tail;
};


#endif /* CommunicationNetwork_h */
