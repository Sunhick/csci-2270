//
//  avl.hpp
//  AVL
//
//  Created by Sunil on 4/10/17.
//  Copyright © 2017 Sunil. All rights reserved.
//

#ifndef avl_hpp
#define avl_hpp

#include <iostream>

struct Node {
    int value;
    Node* left;
    Node* right;
    Node* parent;
    int height;
    
    Node(int v) {
        value = v;
        height = 0;
        left = nullptr;
        right = nullptr;
        parent = nullptr;
    }
};

class AvlTree {
public:
    AvlTree();
    ~AvlTree();
    
    void print();
    int countNodes();
    void deleteNode(int value);
    void addNode(int value);
    bool findNode(int key);
    
private:
    void DeleteAll(Node* node);
    void print(Node* node);
    void countNodes(Node* node, int* c);
    Node* search(int key);
    Node* treeMinimum(Node *node);
    void leftRotate(Node* node);
    void rightRotate(Node* node);
    void addFixup(Node* node);
    void deleteFixup(Node* node);
    int height(Node* node);
    bool isBalanced(Node* node);
    
    Node* root;
};

#endif /* avl_hpp */
