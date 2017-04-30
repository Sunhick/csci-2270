//
//  CollisionCounter.hpp
//  HashTables
//
//  Created by Sunil on 4/29/17.
//  Copyright © 2017 Sunil. All rights reserved.
//

#ifndef CollisionCounter_hpp
#define CollisionCounter_hpp

#include <string>
#include <iostream>

using namespace std;

class CollisionCounter {
private:
    string counterName;
    
public:
    int addCollisions;
    int lookupCollisions;

    CollisionCounter(string name)
    : counterName(name) {
    }
    
    // made inline for performance
    inline void resetCounters() {
        addCollisions = 0;
        lookupCollisions = 0;
    }
    
    inline void showAddCollisions() {
        cout << counterName << " add collisions: " << addCollisions << endl;
    }
    
    inline void showlookupCollisions() {
        cout << counterName << " lookup collisions: " << lookupCollisions << endl;
    }
};

#endif /* CollisionCounter_hpp */
