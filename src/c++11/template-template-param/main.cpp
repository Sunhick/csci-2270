//
//  main.cpp
//  template-template
//
//  Created by Sunil on 2/26/17.
//  Copyright © 2017 Sunil. All rights reserved.
//

#include <iostream>
#include <string>

#include "Map.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    
    std::cout << "container examples" << endl;
    {
        Container<string> array;
        array[0] = "Global.value.0";
        array[1] = "Global.value.1";
        cout << array[0] << endl;
        cout << array[1] << endl;
    }
    
    std::cout << "template-template Map examples" << endl;
    {
        using keytype = int;
        using valuetype = string;
        
        // Map<int, string, Container> dicts;
        // Map<keytype, valuetype, Container> dicts;
        Map<keytype, valuetype> dicts;
        
        dicts[1] = "Global.map.1";
        dicts[14] = "Global.map.14";
        dicts[3] = "Global.map.3";
        
        cout << dicts[14] << endl;
        cout << dicts[3] << endl;
        cout << dicts[1] << endl;
    }
    
    return 0;
}
