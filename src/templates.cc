//
//  main.c
//  test22
//
//  Created by Sunil on 1/31/17.
//  Copyright © 2017 Sunil. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Person {
public:
    string ssn = "000-00-0000";
};


template<typename U>
struct Foo {
    U u;
};

template<typename V>
struct Bar {
    V v;
};

//template<template<typename>class X, typename T>
//struct Com<T<X>> {
//    T<X> tx;
//};

template<typename T>
class List  {
public:
    T *t;
};

// template as template parameter
template<typename T, template<typename>class U>
class Stack {
public:
    U<T> u;
};

int main(int argc, char* argv[]) {
    cout << "hello \n";
    
    vector<int, std::allocator<int>> it;
    
    Bar<Foo<Person>> bar;
    
    Stack<int, List> st;
    
    cout << "hello \n";
    
    return 0;
}
