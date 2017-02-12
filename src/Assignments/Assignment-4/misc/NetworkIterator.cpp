//
//  NetworkIterator.cpp
//  Assignment4
//
//  Created by Sunil on 2/11/17.
//  Copyright © 2017 Sunil. All rights reserved.
//

#ifndef NetworkIterator_cpp
#define NetworkIterator_cpp

#include "NetworkIterator.h"

/**************************************************************************************************/
/* Can't have implementation file for template class.                                             */
/* Everything has to be in the same header file.                                                  */
/*                                                                                                */
/* Alternative solutions are here:                                                                */
/* https://www.codeproject.com/Articles/48575/How-to-define-a-template-class-in-a-h-file-and-imp  */
/**************************************************************************************************/

template<class T>
NetworkIterator<T>::NetworkIterator(typename NetworkTypeTraits<T>::ptr_type start) {
    this->head = start;
}

template<class T>
NetworkIterator<T>::NetworkIterator() {
    this->head = nullptr;
}

template<class T>
NetworkIterator<T>::~NetworkIterator() {
    this->head = nullptr;
}

template<class T>
bool NetworkIterator<T>::operator!=(const NetworkIterator& end) const {
    return this->head != end.head;
}

template<class T>
bool NetworkIterator<T>::operator==(const NetworkIterator& end) const {
    return this->head == end.head;
}

template<class T>
typename NetworkTypeTraits<T>::value_type NetworkIterator<T>::operator*() const {
    return this->head->cityName;
}

template<class T>
typename NetworkTypeTraits<T>::ptr_type NetworkIterator<T>::operator->() const {
    return this->head;
}

template<class T>
NetworkIterator<T>& NetworkIterator<T>::operator++() {
    this->head = this->head->next;
    return *this;
}

template<class T>
NetworkIterator<T> NetworkIterator<T>::operator++(int) {
    NetworkIterator temp(*this);
    this->head = this->head->next;
    return temp;
}

#endif /* NetworkIterator_cpp */
