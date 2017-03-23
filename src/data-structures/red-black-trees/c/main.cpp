//
//  main.cpp
//  rbtree
//
//  Created by Sunil on 3/22/17.
//  Copyright © 2017 Sunil. All rights reserved.
//

#include <iostream>
#include <memory>

#define class struct
#define private public
#define protected public

#include "rbtree.hpp"

#undef class
#undef private
#undef protected

using namespace std;

int main(int argc, const char * argv[]) {
    
    // sample usage of rb trees
    // build a red black tree.
    auto root = new rbnode(45, rbcolor::black);
    
    auto r1 = new rbnode(25);
    r1->parent = root;
    
    auto r2 = new rbnode(60);
    r2->parent = root;
    
    root->left = r1;
    root->right = r2;
    
    rbtree rbt;
    rbt.root = root;
    
    cout << std::boolalpha << rbt.has_equal_black_nodes_all_path(rbt.root) << endl;
    cout << std::boolalpha << rbt.is_valid_rbtree() << endl;

    return 0;
}
