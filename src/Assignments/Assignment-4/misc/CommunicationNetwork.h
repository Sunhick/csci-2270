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

#include "NetworkIterator.h"

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
    using value_type = std::string;
    using elem_type = City;
    using ref_type = City&;
    using ptr_type = City*;
    using const_ptr_type = const City*;
    using iterator_category = std::forward_iterator_tag;
    
    class NetworkIterator : public std::iterator<std::forward_iterator_tag, CommunicationNetwork::value_type> {
    private:
        CommunicationNetwork::ptr_type head;
        
    public:
        NetworkIterator(CommunicationNetwork::ptr_type start);
        NetworkIterator();
        ~NetworkIterator();
        
        bool operator!=(const NetworkIterator& end) const;
        bool operator==(const NetworkIterator& end) const;
        CommunicationNetwork::value_type operator*() const;
        CommunicationNetwork::ptr_type operator->() const;
        NetworkIterator& operator++();
        NetworkIterator operator++(int);
    };

    
    CommunicationNetwork();
    ~CommunicationNetwork();
    void addCity(std::string, std::string);
    void buildNetwork();
    void transmitMsg(char *); //this is like a string
    void printNetwork();
    NetworkIterator begin();
    NetworkIterator end();
    
    
private:
    City *head;
    City *tail;
};

#endif /* CommunicationNetwork_h */
