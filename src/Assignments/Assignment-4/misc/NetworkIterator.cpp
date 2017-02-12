//
//  NetworkIterator.cpp
//  Assignment4
//
//  Created by Sunil on 2/11/17.
//  Copyright © 2017 Sunil. All rights reserved.
//

#include "NetworkIterator.h"

CommunicationNetwork::NetworkIterator::NetworkIterator(CommunicationNetwork::ptr_type start) {
    this->head = start;
}

CommunicationNetwork::NetworkIterator::NetworkIterator() {
    this->head = nullptr;
}

CommunicationNetwork::NetworkIterator::~NetworkIterator() {
    this->head = nullptr;
}

bool CommunicationNetwork::NetworkIterator::operator!=(const NetworkIterator& end) const {
    return this->head != end.head;
}

bool CommunicationNetwork::NetworkIterator::operator==(const NetworkIterator& end) const {
    return this->head == end.head;
}

CommunicationNetwork::value_type CommunicationNetwork::NetworkIterator::operator*() const {
    return this->head->cityName;
}

CommunicationNetwork::ptr_type CommunicationNetwork::NetworkIterator::operator->() const {
    return this->head;
}

CommunicationNetwork::NetworkIterator& CommunicationNetwork::NetworkIterator::operator++() {
    this->head = this->head->next;
    return *this;
}

CommunicationNetwork::NetworkIterator CommunicationNetwork::NetworkIterator::operator++(int) {
    NetworkIterator temp(*this);
    this->head = this->head->next;
    return temp;
}
