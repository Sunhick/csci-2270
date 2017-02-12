//
//  NetworkIterator.cpp
//  Assignment4
//
//  Created by Sunil on 2/11/17.
//  Copyright © 2017 Sunil. All rights reserved.
//

#include "NetworkIterator.h"

/*********************************************************/
/* Can't have implementation file for template class.    */
/* Everything has to be in the same header file.         */
/*********************************************************/

//NetworkIterator<T>::NetworkIterator(typename NetworkTypeTraits<T>::ptr_type start); {
//    this->head = start;
//}
//
//NetworkIterator::NetworkIterator() {
//    this->head = nullptr;
//}
//
//NetworkIterator::~NetworkIterator() {
//    this->head = nullptr;
//}
//
//bool NetworkIterator::operator!=(const NetworkIterator& end) const {
//    return this->head != end.head;
//}
//
//bool NetworkIterator::operator==(const NetworkIterator& end) const {
//    return this->head == end.head;
//}
//
//NetworkTypeTraits::value_type NetworkIterator::operator*() const {
//    return this->head->cityName;
//}
//
//NetworkTypeTraits::ptr_type NetworkIterator::operator->() const {
//    return this->head;
//}
//
//NetworkIterator& NetworkIterator::operator++() {
//    this->head = this->head->next;
//    return *this;
//}
//
//NetworkIterator NetworkIterator::operator++(int) {
//    NetworkIterator temp(*this);
//    this->head = this->head->next;
//    return temp;
//}
