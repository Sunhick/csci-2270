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

template<typename T, typename U>
class List  {
public:
    T *t;
    string name = "Welcome";
};

template<typename T>
class List2  {
public:
    T *t;
};

template<typename T, template<typename, typename>class U>
class Stack {
public:
    typedef U<T,T> Type;
    U<T, T> u;
};

int main(int argc, char* argv[]) {
    cout << "hello \n";
    
    vector<int, std::allocator<int>> it;
    
    Bar<Foo<Person>> bar;
    
    Stack<int, List> st;
    
    Stack<int, List>::Type t;
    
    cout << "hello \n";
    
    return 0;
}
