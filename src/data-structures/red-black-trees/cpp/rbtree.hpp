//
//  rbtree.hpp
//  rbtree
//
//  Created by Sunil on 3/22/17.
//  Copyright © 2017 Sunil. All rights reserved.
//

#ifndef rbtree_hpp
#define rbtree_hpp

#include <iostream>
#include "rbnode.hpp"

////////////////////////////
// Red black tree
////////////////////////////
class rbtree {
private:
    rbnode *root;
    
    rbnode* search(rbnode node, int key);
    bool has_only_red_black_nodes(rbnode* node);
    bool rednode_has_black_children(rbnode* node);
    bool has_equal_black_nodes_all_path(rbnode* parent);
public:
    rbtree();
    ~rbtree();
    
    void insert(int key);
    void remove(int key);
    rbnode* search(int key);
    bool is_valid_rbtree();
    void prune(int min, int max);
    
    void bfs();
    void dfs();
};

#endif /* rbtree_hpp */
