//
//  CommunicationNetwork.cpp
//  Assignment4
//
//  Created by Sunil on 2/11/17.
//  Copyright © 2017 Sunil. All rights reserved.
//

#include "CommunicationNetwork.h"

using namespace std;

CommunicationNetwork::CommunicationNetwork() {
    this->head = nullptr;
    this->tail = nullptr;
}

CommunicationNetwork::~CommunicationNetwork() {
    if(!this->head) {
        // nothing to delete
        return;
    }
    
    City* prevCity = this->head;
    
    while(prevCity) {
        this->head = this->head->next;
        delete prevCity;
        prevCity = this->head;
    }
    
    this->head = nullptr;
    this->tail = nullptr;
}

void CommunicationNetwork::addCity(std::string newCityName, std::string followingCityName) {
    if(!this->head) {
        // no network. Create a network with first city
        this->head = new City(newCityName, nullptr, "");
        this->tail = this->head;
        return;
    }
    
    if(followingCityName.empty()) {
        // if no following city is mentioned, then add to the tail
        this->tail->next = new City(newCityName, nullptr, "");
        this->tail = this->tail->next;
        return;
    }
    
    City* ptr = this->head;
    while(ptr->cityName != followingCityName) {
        ptr = ptr->next;
    }
    
    City* newCity = new City(newCityName, ptr->next, "");
    ptr->next = newCity;
}

void CommunicationNetwork::buildNetwork() {
    string cities[] = {"Los Angeles", "Phoenix", "Denver", "Dallas", "St. Louis", "Chicago", \
        "Atlanta", "Washington, D.C.", "New York", "Boston"};
    
    int size = sizeof(cities)/sizeof(cities[0]);
    for (int i = 0; i < size; i++) {
        this->addCity(cities[i], "");
    }
}

void CommunicationNetwork::transmitMsg(char * msg) { //this is like a string
    City* city = this->head;
    if(!city) {
        // no network
        return;
    }
    
    while(city) {
        city->message = msg;
        cout << city->cityName << " received " << city->message << endl;
        city = city->next;
    }
}

void CommunicationNetwork::printNetwork() {
    cout << "===CURRENT PATH===" << endl;
    
    std::for_each(this->begin(), this->end(), [](string city){
        cout << city << " -> ";
    });

//    City* city = this->head;
//    while(city) {
//        cout << city->cityName << " -> ";
//        city = city->next;
//    }
    cout << "NULL"<< endl;
    cout << "==================" << endl;
}

CommunicationNetwork::NetworkIterator CommunicationNetwork::begin() {
    return NetworkIterator(this->head);
}

CommunicationNetwork::NetworkIterator CommunicationNetwork::end() {
    return NetworkIterator();
}
