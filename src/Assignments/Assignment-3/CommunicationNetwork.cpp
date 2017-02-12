//
//  CommunicationNetwork.cpp
//  Assignment4
//
//  Created by Sunil on 2/11/17.
//  Copyright © 2017 Sunil. All rights reserved.
//

#include <fstream>

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

void CommunicationNetwork::addCity(std::string newCityName, std::string previousCityName) {
    if(!this->head) {
        // no network. Create a network with first city
        this->head = new City(newCityName, nullptr, "");
        this->tail = this->head;
        return;
    }
    
    if(previousCityName.empty()) {
        // if no following city is mentioned, then add to the tail
        this->tail->next = new City(newCityName, nullptr, "");
        this->tail = this->tail->next;
        return;
    }
    
    City* ptr = this->head;
    while(ptr->cityName != previousCityName) {
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

void CommunicationNetwork::transmitMsg(char * filename) { //this is like a string
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
        City* receiver = this->head;
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

void CommunicationNetwork::printNetwork() {
    City* city = this->head;
    
    cout << "===CURRENT PATH===" << endl;
    while(city) {
        cout << city->cityName << " -> ";
        city = city->next;
    }
    cout << "NULL"<< endl;
    cout << "==================" << endl;
}
