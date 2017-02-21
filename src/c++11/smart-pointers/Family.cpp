//
//  Family.cpp
//  SmartPointers
//
//  Created by Sunil on 2/20/17.
//  Copyright © 2017 Sunil. All rights reserved.
//

#include "Family.h"

using namespace std;
using namespace Family;

//////////// Husband ///////////////
Husband::Husband(std::string name) : Husband(name, nullptr) {
    
}

Husband::Husband(std::string name, std::shared_ptr<Wife> wife) {
    this->name = name;
//    this->wife = std::make_shared<Wife>(wife);
//    this->wife.reset(wife);
    this->wife = std::weak_ptr<Wife>(wife);
}

Husband::~Husband() {
    if(!wife.expired()) {
        auto temp = wife.lock();
        cout << "Wife address: " << temp.get() << endl;
    }
    cout << "husband dtor" << this << endl;
}

void Husband::PrintCouples() {
    cout << "Husband: " << name << endl;
    if(!wife.expired()) {
        auto temp = wife.lock();
        cout << "Wife: " << temp->Name() << endl;
        cout << "use count: " << temp.use_count() << endl;
    }
}

std::string Husband::Name() {
    return name;
}

void Husband::SetWife(std::shared_ptr<Wife> wife) {
//    Why make_shared<> doesn't work in constructor? Figure out.
//    this->wife = std::make_shared<Wife>(wife);
//    this->wife.reset(wife);
    this->wife = std::weak_ptr<Wife>(wife);
}

//////////// Wife ///////////////
Wife::Wife(std::string name) : Wife(name, nullptr) {
    
}

Wife::Wife(std::string name, std::shared_ptr<Husband> husband) {
    this->name = name;
//    this->husband = std::make_shared<Husband>(husband);
//    this->husband.reset(husband);
    this->husband = std::weak_ptr<Husband>(husband);
}

Wife::~Wife() {
    if(!husband.expired()) {
        auto temp = husband.lock();
        cout << "Husband address: " << temp.get() << endl;
    }
    cout << "wife dtor" << this << endl;
}

void Wife::PrintCouples() {
    cout << "Wife: " << name << endl;
    if(!husband.expired()) {
        auto temp = husband.lock();
        cout << "Husband: " << temp->Name() << endl;
        cout << "use count: " << temp.use_count() << endl;
    }
}

std::string Wife::Name() {
    return name;
}

void Wife::SetHusband(std::shared_ptr<Husband> husband) {
//    this->husband = std::make_shared<Husband>(husband);
//    this->husband.reset(husband);
    this->husband = std::weak_ptr<Husband>(husband);
}
