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

#include "CommunicationNetwork.h"
//
//class NetworkIterator : public std::iterator<std::forward_iterator_tag, CommunicationNetwork::value_type> {
//private:
//    CommunicationNetwork::ptr_type head;
//
//public:
//    NetworkIterator(CommunicationNetwork::ptr_type start);
//    ~NetworkIterator();
//    
//    bool operator!=(const NetworkIterator& end) const;
//    bool operator==(const NetworkIterator& end) const;
//    CommunicationNetwork::value_type operator*() const;
//    CommunicationNetwork::ptr_type operator->() const;
//    NetworkIterator& operator++();
//    NetworkIterator operator++(int);
//};

#endif /* NetworkIterator_h */
