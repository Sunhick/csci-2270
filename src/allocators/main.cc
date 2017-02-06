//
//  main.cpp
//  Allocators
//
//

#include <iostream>
#include <vector>

#include "allocator.h"

using namespace std;

struct Word {
    string w;
    int f;
    
    Word() {
        cout << "Inside word ctor" << endl;
        w = "Sunil";
        f = 0;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";

    using TAint = TrackingAllocator<int>;
    using TAdouble = TAint::rebind<double>::other;
    
    vector<Word, TrackingAllocator<Word>> v(3);
    cout << v.get_allocator().getAllocations() << endl;
    
    
    
    
    return 0;
}
