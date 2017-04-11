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
    
}

AvlTree::~AvlTree() {
    
}

void AvlTree::print() {
    print(root);
}

int AvlTree::countNodes() {
    return 0;
}

void AvlTree::deleteNode(int value) {
    
}

void AvlTree::addNode(int value) {
    
}

bool AvlTree::findNode(int key) {
    return false;
}

void AvlTree::DeleteAll(Node* node) {
    
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

void AvlTree::leftRotate(Node* node) {
    
}

void AvlTree::rightRotate(Node* node) {
    
}

Node* AvlTree::search(int key) {
    return nullptr;
}

Node* AvlTree::searchRecursive(Node *node, int value) {
    return nullptr;
}

Node* AvlTree::treeMinimum(Node *node) {
    return nullptr;
}
