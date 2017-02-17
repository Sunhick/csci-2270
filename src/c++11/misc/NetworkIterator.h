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
    NetworkIterator(typename NetworkTypeTraits<T>::ptr_type start);
    NetworkIterator();
    ~NetworkIterator();
    bool operator!=(const NetworkIterator<T>& end) const;
    bool operator==(const NetworkIterator<T>& end) const;
    typename NetworkTypeTraits<T>::value_type operator*() const;
    typename NetworkTypeTraits<T>::ptr_type operator->() const;
    NetworkIterator<T>& operator++();
    NetworkIterator<T> operator++(int);
};

#include "NetworkIterator.cpp"

#endif /* NetworkIterator_h */
