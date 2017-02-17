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

int main(int argc, char* argv[]) {
    cout << "hello \n";
    vector<int> v = {1,22,3,-88,3,22, -11};
    
    auto f = std::any_of(begin(v), end(v), [](int val){ return val > 12;});
    auto g = std::all_of(begin(v), end(v), [](int e){ return e < 0; });
    auto e = std::none_of(begin(v), end(v), [](int e){ return e < 0; });
    auto h = std::find_if_not(begin(v), end(v), [](int e){return e > 0;});
    auto i = std::find_if(begin(v), end(v), [](int e){return e < 0;});
    auto l = std::count_if(begin(v), end(v), [](int e){ return e > 0; });
    auto m = std::count(begin(v), end(v), -11);
    
    decltype(v) u(v.size());
    auto j = std::copy_if(begin(v), end(v), begin(u), [](int e){ return e < 0;} );
    u.resize(std::distance(begin(u), j));
    
    std::partition(begin(v), end(v), [](int i) {return i < 0; });
    auto k = std::is_partitioned(begin(v), end(v), [](int i) {return i < 0; });
    
    auto n = std::min_element(begin(v), end(v), [](int a,int b){ return a < b;});
    auto o = std::max_element(begin(v), end(v), [](int a,int b){ return a < b;});
    
    std::for_each(begin(v), end(v), [](int& e) { e = 121; });
    
    cout << "val = " << f << endl;
    cout << "val = " << g << endl;
    cout << "val = " << e << endl;
    cout << "val = " << *h << endl;
    cout << "val = " << *i << endl;
    cout << "val = " << k << endl;
    cout << "val = " << l << endl;
    cout << "val = " << m << endl;
    cout << "val = " << *n << endl;
    cout << "val = " << *o << endl;
    cout << __cplusplus << endl;
    
    for(auto ee : v) {
        cout << ee << endl;
    }
    
    return 0;
}
