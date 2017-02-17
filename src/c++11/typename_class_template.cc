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

class Car {
public:
    class Demo {
    public:
        int ab = 56;
        string name = "hello";
    };
};

template<class T>
class Exp {
public:
    typename T::Demo *ab = new typename T::Demo;
};

int main(int argc, char* argv[]) {
    cout << "hello \n";
    Exp<Car> p;
    cout << "World" << endl;
    return 0;
}
