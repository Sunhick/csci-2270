//
//  learn.hpp
//  traits
//
//  Created by Sunil on 2/20/17.
//  Copyright © 2017 Sunil. All rights reserved.
//

#ifndef learn_hpp
#define learn_hpp

#include <iostream>

using namespace std;

#define nameof(x) #x

template<class T>
struct Node {
    T data;
    Node() {}
    Node(T v) { data = v;}
    using value_type = T;
};

template<class  T>
class Sequence {
private:
    Node<T> *head;
    int index;
    
public:
    using element_type = T;
    using internal_type = Node<T>;
    
    void Add(T value);
    T Pop();
    Node<T> GetNode();
    Sequence();
    ~Sequence();
};

template<class T>
Sequence<T>::~Sequence() {
    delete[] head;
    index = -1;
}

template<class T>
Sequence<T>::Sequence() {
    head = new Node<T>[10];
    index = -1;
}

template <class T>
void Sequence<T>::Add(T value) {
    head[++index] = Node<T>{ value };
}

template <class T>
T Sequence<T>::Pop() {
    auto o =  head[index--].data;
    cout << o << endl;
    return o;
}

template <class T>
Node<T> Sequence<T>::GetNode() {
    return head[index--];
}

template <class Container>
void Process(Container &c, int size) {
    typename Container::element_type i = 0;
    for(int k = 0; k < size; k++) {
        i += c.Pop();
    }
    
    cout << i << endl;
    cout << "hello" << endl;
}

template<int T>
struct Factorial {
    static const int value = T * Factorial<T-1>::value;
};

template<>
struct Factorial<0> {
    static const int value = 1;
};

template<class U>
struct PointerCount {
    static const int value = 0;
};

template<class U>
struct PointerCount<U*> {
    static const int value = 1 + PointerCount<U>::value;
};

template<class Type>
void PrintPointerCount() {
    int count = PointerCount<Type>::value;
    cout << "* count: " << count << endl;
}

template<class Type>
void PrintPointerCount(Type) {
    cout << typeid(Type).name() << endl;
    PrintPointerCount<Type>();
}

template<int value>
void PrintValue() {
    cout << value << endl;
}

struct Null { };

template<int Value_, typename Next_>
struct TNode {
    static const int value = Value_;
    using Next = Next_;
};

template<int i>
struct EvalHelper;

#define EVAL(t) EvalHelper<t::value>

#endif /* learn_hpp */
