//
//  main.cpp
//  casting
//
//  Created by Sunil on 2/21/17.
//  Copyright © 2017 Sunil. All rights reserved.
//

#include <iostream>
#include <memory>

#include "base.hpp"
#include "derived.hpp"

using namespace std;

struct Person {
    string name;
    int id;
};

struct Doppelganger {
    string name;
    int id;
    bool fake = true;
    
    Doppelganger(string n, int i) {
        name =  n;
        id = i;
    }
};

void logAndPrint(shared_ptr<base> p) {
    cout << "In log " << p.use_count() << endl;
    // dynamic_pointer_cast is only experimental.
    // ref: http://en.cppreference.com/w/cpp/experimental/shared_ptr/pointer_cast
    // auto d = dynamic_pointer_cast<derived>(p);
    
    // C++11 casting:
    // * const_cast, reinterpret_cast, dynamic_cast, static_cast
    // * static_pointer_cast, const_pointer_cast, dynamic_pointer_cast
    auto d = dynamic_pointer_cast<derived>(p);
    if (d) {
        //d->extraPrint();
        d->extraPrint();
    }
    
    if (p) {
        p->print();
    }
}

// ref: https://arne-mertz.de/2015/01/a-casting-show/
void nochange(const Person& person) {
    // person object shouldn't be changed.
    // person.name = "changed!"; // error
    
    // throw away the constness and change it anyway!
    Person& sudo = const_cast<Person&>(person);
    sudo.name = "changed!";
    sudo.id = 56;
}

// reinterpret_cast works only with pointers on unrelated types
void fake(Person* p) {
    cout << "person: " << p->name << " " << p->id << endl;
    Doppelganger* d = reinterpret_cast<Doppelganger*>(p);
    if(d && d->fake) {
        cout << boolalpha << "fake person: " << d->name << " " << d->id << d->fake << endl;
    }
}

// void fake(Doppelganger* p) {
//     Doppelganger* d = reinterpret_cast<Doppelganger*>(p);
//     if(d) {
//         cout << boolalpha << "fake person: " << d->name << " " << d->id << d->fake << endl;
//     }
// }

// static_cast: aware of narrowing
// caution: Also works if dynamic types are known and gaurenteed at runtime
void convert(float f) {
    int v = static_cast<int>(f);
    cout << "val = " << v << endl;
}

// dynamic_cast used for downcasts/ crosscasts on related types(class hierarchy).
// works only on pointers
void downcast(base* b) {
    derived* d = dynamic_cast<derived*>(b);
    if (d) {
        d->extraPrint();
        d->print();
    }
}

int main(int argc, const char * argv[]) {
    
    cout << "const_cast example" << endl;
    {
        Person p = {.name="Sunil", .id = 99};
        nochange(p);
        cout << p.name << " " << p.id << endl;
    }
    cout << "-----------------" << endl;
    
    cout << "reinterpret_cast example" << endl;
    {
        Person p = {.name="Sunil", .id = 99};
        fake(&p);
        
        Doppelganger f("Hello",98);
        fake(reinterpret_cast<Person*>(&f));
    }
    cout << "-----------------" << endl;

    cout << "static_cast example" << endl;
    {
        float d = 45.454656;
        convert(d);
    }
    cout << "-----------------" << endl;
    
    cout << "dynamic_cast example" << endl;
    {
        auto b = new derived("hello");
        downcast(b);
        delete b;
        
        Person p = {"Sunil", 56};
        // Doppelganger* d = dynamic_cast<Doppelganger*>(&p); // error . unrelated types
        Doppelganger* d = reinterpret_cast<Doppelganger*>(&p);
        if(d) {
            cout << d->name << d->id << d->fake << endl;
        }
    }
    cout << "-----------------" << endl;
    
    cout << "base pointing to base" << endl;
    {
        shared_ptr<base> b(new base("base"));
        b->print();
        logAndPrint(b);
    }
    cout << "-----------------" << endl;
    
    cout << "derived pointing to derived" << endl;
    {
        shared_ptr<derived> d(new derived("derived"));
        d->print();
        logAndPrint(d);
    }
    cout << "-----------------" << endl;
    
    cout << "base pointing to derived" << endl;
    {
        shared_ptr<base> d(new derived("derived"));
        d->print();
        logAndPrint(d);
    }
    cout << "-----------------" << endl;
    
    cout << "experimenting with smart pointers." << endl;
    {
        logAndPrint(nullptr);
        if (nullptr == NULL) {
            cout << "nullptr and NULL are one and the same" << endl;
        }
        shared_ptr<shared_ptr<base>> b(new shared_ptr<base>(new base("weird")));
        b->operator->()->print();
    }
    cout << "-----------------" << endl;
    
    return 0;
}
