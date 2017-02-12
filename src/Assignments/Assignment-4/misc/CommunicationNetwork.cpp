//
//  CommunicationNetwork.cpp
//  Assignment4
//
//  Created by Sunil on 2/11/17.
//  Copyright © 2017 Sunil. All rights reserved.
//
#include <fstream>
#include <algorithm>

#ifndef CommunicationNetwork_cpp
#define CommunicationNetwork_cpp

#include "CommunicationNetwork.h"

using namespace std;

template<class T>
struct DefaultValues {
    static T dval;
    static T values[];
    enum {size = 10 };
};

template<class T>
CommunicationNetwork<T>::CommunicationNetwork() {
    this->head = nullptr;
    this->tail = nullptr;
}

template<class T>
CommunicationNetwork<T>::~CommunicationNetwork() {
    if(!this->head) {
        // nothing to delete
        return;
    }
    
    typename CommunicationNetwork<T>::ptr_type prevCity = this->head;
    
    while(prevCity) {
        this->head = this->head->next;
        delete prevCity;
        prevCity = this->head;
    }
    
    this->head = nullptr;
    this->tail = nullptr;
}

template<class T>
void CommunicationNetwork<T>::addCity(T newCityName, T followingCityName) {
    if(!this->head) {
        // no network. Create a network with first city
        this->head = new City<typename CommunicationNetwork::value_type>(newCityName, nullptr, "");
        this->tail = this->head;
        return;
    }
    
//    if(followingCityName.empty()) {
//        // if no following city is mentioned, then add to the tail
//        this->tail->next = new City<typename CommunicationNetwork::value_type>(newCityName, nullptr, "");
//        this->tail = this->tail->next;
//        return;
//    }
    
    typename CommunicationNetwork<T>::ptr_type ptr = this->head;
    while(ptr->cityName != followingCityName) {
        if(!ptr->next) break;
        ptr = ptr->next;
    }
    
    typename CommunicationNetwork<T>::ptr_type newCity = new City<typename CommunicationNetwork::value_type>(newCityName, ptr->next, "");
    ptr->next = newCity;
}

template<class T>
void CommunicationNetwork<T>::buildNetwork() {
    for(T each : DefaultValues<T>::values) {
        cout << each << endl;
        this->addCity(each, DefaultValues<T>::dval);
    }
}

template<class T>
void CommunicationNetwork<T>::transmitMsg(char *filename) { //this is like a string
    ifstream file(filename);
    
    // non-existant or corrupted file
    if(file.fail()) {
        return;
    }
    
    // no network
    if(!this->head) {
        cout << "Empty list" << endl;
        return;
    }
    
    std::string word;
    while(std::getline(file, word, ' ')) {
        // remove the newline from the word if it has.
        word.erase(std::remove(word.begin(), word.end(), '\n'), word.end());
        typename CommunicationNetwork<T>::ptr_type receiver = this->head;
        while(receiver) {
            // set the message
            receiver->message = word;
            cout << receiver->cityName << " received " << receiver->message << endl;
            
            // delete the message
            receiver->message = "";
            receiver = receiver->next;
        }
    }
}

template<class T>
void CommunicationNetwork<T>::printNetwork() {
    cout << "===CURRENT PATH===" << endl;
    
    std::for_each(this->begin(), this->end(), [](typename CommunicationNetwork<T>::value_type city){
        cout << city << " -> ";
    });

    cout << "NULL"<< endl;
    cout << "==================" << endl;
}

#endif /* CommunicationNetwork_cpp */
