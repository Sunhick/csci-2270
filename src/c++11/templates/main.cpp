//
//  main.cpp
//  traits
//
//  Created by Sunil on 2/19/17.
//  Copyright © 2017 Sunil. All rights reserved.
//

#include <iostream>

#include "learn.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    cout << "-----------------" << endl;
    Sequence<float> seq;
    seq.Add(12.12);
    seq.Add(121.121);
    seq.Add(1212.1212);
    
    cout << 12.12 + 121.121 + 1212.1212 << endl;
    Process(seq, 3);
    int p = seq.Pop();
    typename Sequence<float>::internal_type e = seq.GetNode();
    cout << p << endl << e.data << endl;
    
    cout << "-----------------" << endl;
    PrintPointerCount<int>();
    PrintPointerCount<char*>();
    PrintPointerCount<char**>();
    PrintPointerCount<int*******>();
    PrintPointerCount<Node<int>****>();

    Node<int>********** pp;
    PrintPointerCount(pp);
    
    cout << "-----------------" << endl;
    PrintValue<12>();
    constexpr int k = 9;
    PrintValue<k>();
    
    cout << "-----------------" << endl;
    constexpr auto n=6;
//    cin >> n;  // This is not allowed. As templates are instantiated at compile time.
    cout << Factorial<n>::value << endl;
    
    cout << "-----------------" << endl;
    TNode< 1, TNode<2, Null>> tp;
    cout << tp.value << endl;
        
    return 0;
}
