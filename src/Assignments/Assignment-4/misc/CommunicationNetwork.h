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

template<class T = std::string>
class CommunicationNetwork : public NetworkTypeTraits<T> {
public:
    CommunicationNetwork();
    ~CommunicationNetwork();
    void addCity(T, T);
    void buildNetwork();
    void transmitMsg(char *); //this is like a string
    void printNetwork();
    NetworkIterator<T> begin() {
        return NetworkIterator<T>(this->head);
    }
    
    NetworkIterator<T> end() {
        return NetworkIterator<T>();
    }
    
private:
    typename NetworkTypeTraits<T>::ptr_type head;
    typename NetworkTypeTraits<T>::ptr_type tail;
};

#include "CommunicationNetwork.cpp"

#endif /* CommunicationNetwork_h */
