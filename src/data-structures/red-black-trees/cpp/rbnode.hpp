//
//  rbnode.hpp
//  rbtree
//
//  Created by Sunil on 3/22/17.
//  Copyright © 2017 Sunil. All rights reserved.
//

#ifndef rbnode_hpp
#define rbnode_hpp

enum rbcolor {
    red,
    black
};

class rbnode {
public:
    int key;
    rbnode *left;
    rbnode *right;
    rbnode *parent;
    rbcolor color;
    
    // ctor and dtor
    rbnode(int key, rbcolor color = rbcolor::red, rbnode *parent = nullptr, \
           rbnode *left = nullptr, rbnode *right = nullptr);
    ~rbnode();
    
    bool is_red_node();
    bool is_black_node();
};

#endif /* rbnode_hpp */
