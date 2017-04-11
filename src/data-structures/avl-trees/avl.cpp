//
//  avl.cpp
//  AVL
//
//  Created by Sunil on 4/10/17.
//  Copyright © 2017 Sunil. All rights reserved.
//

#include "avl.hpp"

using namespace std;

AvlTree::AvlTree() {
    root = nullptr;
}

AvlTree::~AvlTree() {
    if (!root) {
        return;
    }
    
    DeleteAll(root);
    root = nullptr;
}

void AvlTree::print() {
    print(root);
}

int AvlTree::countNodes() {
    int count = 0;
    countNodes(root, &count);
    return count;
}

void AvlTree::deleteNode(int value) {
    
}

void AvlTree::addNode(int value) {
    
}

bool AvlTree::findNode(int key) {
    return search(key) != nullptr;
}

void AvlTree::DeleteAll(Node* node) {
    if (!node) {
        return;
    }
    
    DeleteAll(node->left);
    DeleteAll(node->right);
    
    delete node;
    node = nullptr;
}

void AvlTree::print(Node* node) {
    if (!node) return;
    
    cout << node->value << endl;
    print(node);
    print(node);
}

void AvlTree::countNodes(Node* node, int* c) {
    if (!node) {
        *c = 0;
        return;
    }
    
    (*c)++;
    countNodes(node->left, c);
    countNodes(node->right, c);
}

void AvlTree::rightRotate(Node* y) {
    /*
             y                                        x
            / \        right rotate around y         / \
           x   c     ----------------------->       a   y
          / \                                          / \
         a   b                                        b   c
     
     */
    
    auto x = y->left;
    
    // get right subtree of x if available.
    // otherwise set it to nullptr.
    auto b = x ? x->right : nullptr;
    
    // turn x's right subtree into a y's left subtree.
    y->left = b;
    
    if (b) {
        b->parent = y;
    }
    
    // set parent of x to y's parent.
    x->parent = y->parent;
    
    // if y doesn't have a parent, make x as root.
    if (!y->parent) {
        root = x;
    }
    // parent is not null, see if y is to left/right of parent.
    else if (y->parent->left == y) {
        y->parent->left = x;
    }
    else {
        y->parent->right = x;
    }
    
    x->right = y;
    y->parent = x;
}

void AvlTree::leftRotate(Node* x) {
    /*
            x                                          y
           / \          left rotate around x          / \
          a   y       ------------------------>      x   c
             / \                                    / \
            b   c                                  a   b
     */
    
    auto y = x->right;
    
    // get left subtree of y if available.
    // otherwise set it to nullptr.
    auto b = y ? y->left : nullptr;
    
    // no need to get c, as it stays unaffected by left rotation.
    
    // turn y's left subtree into a x's right subtree.
    x->right = b;
    if (b) {
        b->parent = x;
    }
    
    // set parent of y to x's parent.
    y->parent = x->parent;
    
    // if x doesn't have a parent, make y as root.
    if (!x->parent) {
        root = y;
    }
    // parent is not null, see if x is to left/right of parent.
    else if (x->parent->left == x) {
        x->parent->left = y;
    }
    else {
        x->parent->right = y;
    }
    
    y->left = x;
    x->parent = y;
}

Node* AvlTree::search(int key) {
    if (!root) {
        return nullptr;
    }
    
    auto temp = root;
    
    while (temp) {
        if (temp->value == key) break;
        temp = key > temp->value ? temp->right : temp->left;
    }
    
    return temp;
}

Node* AvlTree::treeMinimum(Node* node) {
    if (!node) {
        return nullptr;
    }
    
    while(node->left) {
        node = node->left;
    }
    
    return node;
}

void AvlTree::addFixup(Node* node) {
    // TODO: called after adding a node to bst to restore the balance
}

void AvlTree::deleteFixup(Node* node) {
    // TODO: called after deleting a node to bst to restore the balance
}
