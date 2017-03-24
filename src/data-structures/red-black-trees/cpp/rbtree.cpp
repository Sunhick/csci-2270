//
//  rbtree.cpp
//  rbtree
//
//  Created by Sunil on 3/22/17.
//  Copyright © 2017 Sunil. All rights reserved.
//

#include "rbtree.hpp"

#include <tuple>
#include <stack>
#include <list>
#include <iostream>

using namespace std;

rbnode* rbtree::search(rbnode node, int key) {
    return nullptr;
}

rbtree::rbtree() {
    
}

rbtree::~rbtree() {
    remove_all(root);
}

void rbtree::remove_all(rbnode* node) {
    if (!node) {
        // no node to delete
        return;
    }
    
    if (node->left)
        remove_all(node->left);
    if (node->right)
        remove_all(node->right);
    
    delete node;
}

void rbtree::remove(int key) {
    // TODO: after removing the node, rebalance the tree.
}

bool rbtree::violates(bool constraint) {
    // just negate the constraint and return
    return !constraint;
}

void rbtree::insert(int key) {
    
}

bool rbtree::has_only_red_black_nodes(rbnode* node) {
    if (!node) {
        // no nodes, no color.
        return false;
    }
    
    // use any tree traversal and check the color
    
    // everynode has to be red or black.
    if (!node->is_red_node() && !node->is_black_node()) {
        // this node is neither red nor black. It's a invalid rb tree.
        return false;
    }
    
    // node has red/black color but doesn't have left or right subtree.
    if (!node->left && !node->right) {
        return true;
    }
    
    // only right subtree is available.
    if (!node->left && node->right) {
        return has_only_red_black_nodes(node->right);
    }
    
    // only left subtree is available.
    if (!node->right && node->left) {
        return has_only_red_black_nodes(node->left);
    }
    
    // Both left "and" right subtree should have only red/black nodes.
    return (
        has_only_red_black_nodes(node->left) && has_only_red_black_nodes(node->right)
            );
}

bool rbtree::rednode_has_black_children(rbnode* parent) {
    if (!parent) {
        // no node, no children. Nothing to check
        return false;
    }
    
    // if node is red, then check it's children
    if (parent->is_red_node()) {
        
        // if left and right children are null treat them as black.
        if (!parent->left && !parent->right) {
            return true;
        }
        
        // both left and right are available.
        if ((parent->left && parent->left->is_red_node())
            || (parent->right && parent->right->is_red_node())) {
            return false;
        }
        
        // left child is not null. make sure its color is black
        if (parent->left && parent->left->is_red_node()) {
            // left child is not black.
            return false;
        }
        
        // right child is not null. make sure its color is black
        if (parent->right && parent->right->is_red_node()) {
            // right child is not black.
            return false;
        }
    }
    
    
    // only right subtree is available.
    if (!parent->left && parent->right) {
        return has_only_red_black_nodes(parent->right);
    }
    
    // only left subtree is available.
    if (!parent->right && parent->left) {
        return has_only_red_black_nodes(parent->left);
    }
    
    // Both left "and" right subtree
    return (
            has_only_red_black_nodes(parent->left) && has_only_red_black_nodes(parent->right)
            );
}

bool rbtree::has_equal_black_nodes_all_path(rbnode* parent) {
    // do a depth first search traversal and count the black nodes
    // along all path from root to leaf node.
    if (!parent) {
        // no nodes. return true or false ?
        return true;
    }
    // stack of tuple of (node, count of black nodes) pair.
    stack<tuple<rbnode*, int>> stk;
    list<int> paths;
    
    auto count_if_black = [](rbnode* node) {
        return (node->is_black_node() ? 1 : 0);
    };
    
    stk.push(make_tuple(parent, count_if_black(parent)));
    
    while (!stk.empty()) {
        auto pair = stk.top();
        stk.pop();
        
        auto node = std::get<0>(pair);
        auto count = std::get<1>(pair);
        
        if (node->left) {
            auto left = node->left;
            stk.push(make_tuple(left, count + count_if_black(left)));
        } else {
            // left child is null. count it as a black node.
            paths.push_front(count + 1);
        }
        
        if (node->right) {
            auto right = node->right;
            stk.push(make_tuple(right, count + count_if_black(right)));
        } else {
            // right child is null. count it as a black node.
            paths.push_front(count + 1);
        }
    }
    
    // now check if black node count on all paths are same.
    auto first = paths.front();
    
#if DEBUG
    for (auto count : paths) cout << count << "|";
    cout << endl;
#endif
    
    for (auto count : paths) {
        if (count != first)
            return false;
    }
    
    
    return true;
}

bool rbtree::is_valid_rbtree() {
    // rb tree properties:
    //  P.1: every node is red/black.
    //  P.2: root is always black.
    //  P.3: leaf nodes are black.
    //  P.4: red node should have only black children.
    //  P.5: for any node x, # of black nodes along all
    //       paths from x to leaf nodes should be the same.
    
    if (!root) {
        // no nodes in the tree, is a valid RB tree
        return true;
    }
    
    // P.1: check if all nodes are red/ black.
    if (violates(has_only_red_black_nodes(root))) {
        // some nodes are of different color. It's not a red black tree
        return false;
    }
    
    // P.2: If root is not black then it's invalid.
    if (violates(root->is_black_node()))
        return false;
    
    // P.3: I take all null nodes to be black.
    // I treat all null nodes as black. So I don't have to
    // check for black null nodes.
    
    // P.4: all red nodes should have black children.
    if (violates(rednode_has_black_children(root))) {
        // some/all of red nodes doesn't have a black children
        return false;
    }
    
    // P.5:  check #black nodes along all possible path from root
    //  to leaf nodes.
    if (violates(has_equal_black_nodes_all_path(root))) {
        // unequal number of black nodes.
        return false;
    }
    
    return true;
}

rbnode* rbtree::search(int key) {
    return nullptr;
}

void rbtree::prune(int min, int max) {
    throw new runtime_error("not implemented");
}

void rbtree::bfs() {
    throw new runtime_error("not implemented");
}

void rbtree::dfs() {
    throw new runtime_error("not implemented");
}
