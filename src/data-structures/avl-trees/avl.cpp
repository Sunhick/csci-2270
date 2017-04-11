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

int AvlTree::height(Node* node) {
    return node ? node->height : 0;
}

void AvlTree::addNode(int value) {
    auto node = new Node(value);
    
    // update the height
    node->height = 1;
    
    if (root == nullptr) {
        // no root.
        root = node;
        return;
    }
    
    auto temp = root;
    auto parent = root;
    
    while (temp) {
        parent = temp;
        parent->height += 1;
        temp = value > temp->value ? temp->right : temp->left;
    }
    
    // parent shouldn't be nullptr at this point.
    node->parent = parent;
    
    if (value > parent->value) parent->right = node;
    else parent->left = node;
    
    addFixup(node);
    
    if (!isBalanced(root)) {
        // No need for new runtime_error here. If i do new, who's responsible for delete ?
        // It's better use copy ctor here and let the object delete on it's own (out of scope).
        // Hence all exceptions in c++ should be copyable to avoid resposibility of deletion of
        // newly created exception object.
        // throw new runtime_error("Tree is not balanced!"); // bad practice. delete ?
        
        // Also some compiler may elide copy ctor (a way to avoid unnecessary copies).
        throw runtime_error("Tree is not balanced!");
    }
}

bool AvlTree::isBalanced(Node* node) {
    // TODO: implement this
    return false;
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
