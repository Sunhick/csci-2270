//
//  rbnode.cpp
//  rbtree
//
//  Created by Sunil on 3/22/17.
//  Copyright © 2017 Sunil. All rights reserved.
//

#include "rbnode.hpp"

#include <iostream>

using namespace std;

rbnode::rbnode(int key, rbcolor color, rbnode *left, rbnode *right, rbnode *parent) {
    // rb node constructor
    this->key = key;
    this->left = left;
    this->right = right;
    this->parent = parent;
    this->color = color;
}

rbnode::~rbnode() {
    cout << "rbnode dtor called" << endl;
}

bool rbnode::is_red_node() {
    return (this->color == rbcolor::red);
}

bool rbnode::is_black_node() {
    return (this->color == rbcolor::black);
}
