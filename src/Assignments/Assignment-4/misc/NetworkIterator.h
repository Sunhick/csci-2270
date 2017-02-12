//
//  NetworkIterator.hpp
//  Assignment4
//
//  Created by Sunil on 2/11/17.
//  Copyright © 2017 Sunil. All rights reserved.
//

#ifndef NetworkIterator_h
#define NetworkIterator_h

#include <iterator>

#include "NetworkTypeTraits.h"

template<class T>
class NetworkIterator : public std::iterator<std::forward_iterator_tag, typename NetworkTypeTraits<T>::value_type> {
private:
    typename NetworkTypeTraits<T>::ptr_type head;
    
public:
    NetworkIterator(typename NetworkTypeTraits<T>::ptr_type start) {
        this->head = start;
    }
    
    NetworkIterator() {
        this->head = nullptr;
    }
    
    ~NetworkIterator() {
        this->head = nullptr;
    }
    
    bool operator!=(const NetworkIterator& end) const {
        return this->head != end.head;
    }
    
    bool operator==(const NetworkIterator& end) const {
        return this->head == end.head;
    }
    
    typename NetworkTypeTraits<T>::value_type operator*() const {
        return this->head->cityName;
    }
    
    typename NetworkTypeTraits<T>::ptr_type operator->() const {
        return this->head;
    }
    
    NetworkIterator& operator++() {
        this->head = this->head->next;
        return *this;
    }
    
    NetworkIterator operator++(int) {
        NetworkIterator temp(*this);
        this->head = this->head->next;
        return temp;
    }
};

#endif /* NetworkIterator_h */
