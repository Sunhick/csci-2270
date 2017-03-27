//
//  MovieTree.cpp
//  Assignment10
//
//  Created by Sunil on 3/27/17.
//  Copyright © 2017 Sunil. All rights reserved.
//

#include "MovieTree.h"
#include <iostream>

using namespace std;

// Returns 0 if the tree is invalid, otherwise returns the black node height.
int MovieTree::rbValid(MovieNode * node)
{
    int lh = 0;
    int rh = 0;
    
    // If we are at a nil node just return 1
    if (node == nil)
        return 1;
    
    else
    {
        // First check for consecutive red links.
        if (node->isRed)
        {
            if(node->leftChild->isRed || node->rightChild->isRed)
            {
                cout << "This tree contains a red violation" << endl;
                return 0;
            }
        }
        
        // Check for valid binary search tree.
        if ((node->leftChild != nil && node->leftChild->title.compare(node->title) > 0) || (node->rightChild != nil && node->rightChild->title.compare(node->title) < 0))
        {
            cout << "This tree contains a binary tree violation" << endl;
            return 0;
        }
        
        // Deteremine the height of let and right children.
        lh = rbValid(node->leftChild);
        rh = rbValid(node->rightChild);
        
        // black height mismatch
        if (lh != 0 && rh != 0 && lh != rh)
        {
            cout << "This tree contains a black height violation" << endl;
            return 0;
        }
        
        // If neither height is zero, incrament if it if black.
        if (lh != 0 && rh != 0)
        {
            if (node->isRed)
                return lh;
            else
                return lh+1;
        }
        
        else
            return 0;

    }
}

MovieTree::MovieTree() {
    
}

MovieTree::~MovieTree() {
    
}

void MovieTree::printMovieInventory() {
    
}

int MovieTree::countMovieNodes() {
    return 0;
}

void MovieTree::deleteMovieNode(std::string title) {
    
}

void MovieTree::addMovieNode(int ranking, std::string title, int releaseYear, int quantity) {
    
}

void MovieTree::findMovie(std::string title) {
    
}

void MovieTree::rentMovie(std::string title) {
    
}

bool MovieTree::isValid() {
    return false;
}

int MovieTree::countLongestPath() {
    return 0;
}

void MovieTree::DeleteAll(MovieNode * node) {
    //use this for the post-order traversal deletion of the tree
}

void MovieTree::printMovieInventory(MovieNode * node) {
    
}

void MovieTree::rbAddFixup(MovieNode * node) {
    // called after insert to fix tree
}

void MovieTree::leftRotate(MovieNode * x) {
    //rotate the tree left with x as the root of the rotation
}
void MovieTree::rbDelete(MovieNode * z) {
    //delete a node. Call this from deleteMovieNode, the actual delete functionality happens here.
}

void MovieTree::rightRotate(MovieNode * x) {
    //rotate the tree right with x as the root of the rotation
}
void MovieTree::rbDeleteFixup(MovieNode * node) {
    //called after delete to fix the tree
}
void MovieTree::rbTransplant(MovieNode * u, MovieNode * v) {
    //replace node u in tree with node v. Your solution doesn't necessarily need to use this method

}

int MovieTree::countMovieNodes(MovieNode *node) {
    //number of unique titles in the tree
    return 0;
}

int MovieTree::countLongestPath(MovieNode *node) {
    //longest path from node to a leaf node in the tree
    return 0;
}
MovieNode* MovieTree::searchMovieTree(MovieNode * node, std::string title) {
    return nullptr;
}
