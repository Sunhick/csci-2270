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

void print(int *a, int size)  {
    std::for_each(a, a+size, [](int& i){
        cout << i << " ";
    });
    std::cout << endl;
}

[[deprecated("use print instead")]]
void funcPrint(int *a, int size, std::function<int(int&)> func) {
    std::for_each(a, a+size, [func](int& i) {
        int k = func(i);
        cout << k << "-";
    });
    cout << endl;
}

struct Word {
    string w = "<Default>";
    int count;
};

long long operator "" _km(unsigned long long literal) {
    return literal * 1000;
}

#define PRINT(name) cout << #name << endl

int main(int argc, char* argv[]) {
    
    int a[] = {9,2,3,4,5,6,7,8,1, 0};
    int b[10];
    
    
    std::sort(a, a+10, [](int& a, int& b){
        return a < b;
    });
    
    std::function<int(int&)> lambda = [](int&i) { return i*2; };
    std::transform(std::begin(a), std::end(a), std::begin(b), lambda);
   
    std::cout.setf(std::ios::boolalpha);
    cout << std::is_sorted(a, a+10, [](int& a, int& b){
        return a < b;
    }) << endl;
    
    auto func = [](int& i){
        return i*3;
    };
    
    int var_name_is_ridiculous = 45;
    PRINT(SUNIL IS GRAD STUDENT);
    
    funcPrint(a, 10, func);
    
    auto million = 1'00'000'000;
    cout << million << endl;
    
    Word w = { .count = 77, .w =  "hello"};
    cout << w.w << w.count  << endl;
    
    print(a, 10);
    print(b, 10);
    cout << __gcd(18, 27) << endl;
    string license = R"("This is a simple
    text from the license plate.\t\b\n\rr
    I don't know what i'm" writing here... hahaha)";

    cout << license << endl;
    
    cout << 12_km << " meters \n"; // Prints 12000 meters
    return 0;
    
}
