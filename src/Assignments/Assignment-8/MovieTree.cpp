//
//  MovieTree.cpp
//  Assignment-8
//
//  Created by Sunil on 3/11/17.
//  Copyright © 2017 Sunil. All rights reserved.
//

#include "MovieTree.h"

#include <iostream>

using namespace std;

MovieTree::MovieTree() {
    root = nullptr;
}

MovieTree::~MovieTree() {
    DeleteAll(root);
}

void MovieTree::printMovieInventory() {
    printMovieInventory(root);
}

int MovieTree::countMovieNodes() {
    int count = 0;
    countMovieNodes(root, &count);
    return count;
}

void MovieTree::deleteMovieNode(std::string title) {
    auto node = search(title);
    if (!node) {
        //If movie not found in tree
        cout << "Movie not found." << endl;
        return;
    }
    
    // movie found. delete it.
    
    // case 1: node has no children.
    if (!node->leftChild && !node->rightChild) {
        cout << "case 1" << endl;
        // check if parent is availble.
        if (node->parent) {
            // check where the node is present relative to it's parent.
            if (node->parent->leftChild == node) {
                node->parent->leftChild = nullptr;
            } else {
                node->parent->rightChild = nullptr;
            }
        } else {
            // If not, then it's a root. If it's root with no left/ right
            // child, then delete it.
            root = nullptr;
        }
        
        delete node;
        return;
    }
    
    // case 2: node has only 1 child
    if (node->leftChild && !node->rightChild) {
        cout << "case 2 Left" << endl;
        node->leftChild->parent = node->parent;
        //see if there's a parent.
        if (node->parent) {
            // check where the node is present relative to it's parent.
            if (node->parent->leftChild == node) {
                node->parent->leftChild = node->leftChild;
            } else {
                node->parent->rightChild = node->leftChild;
            }
        } else {
            // root with only left child
            root = root->leftChild;
        }
        delete node;
        return;
    }
    
    if (!node->leftChild && node->rightChild) {
        cout << "case 2 Right" << endl;
        node->rightChild->parent = node->parent;
        //see if there's a parent.
        if (node->parent) {
            // check where the node is present relative to it's parent.
            if (node->parent->leftChild == node) {
                node->parent->leftChild = node->rightChild;
            } else {
                node->parent->rightChild = node->rightChild;
            }
        } else {
            // root with only right child
            root = root->rightChild;
        }
        delete node;
        return;
    }
    
    // case 3: node has both left and right child
    // pick the min value from the right subtree
    auto minNode = treeMinimum(node->rightChild);
    cout << "MinNode <<<<< " << endl;
    if (minNode) {
        cout << "Replacement: " << minNode->title << endl;
    }
    
    // It would be easier to copy value from minNode to node and delete minNode.
    // Rather than swapping the minNode with node and update a bunch of links!
    node->title = minNode->title;
    node->ranking = minNode->ranking;
    node->quantity = minNode->quantity;
    node->year = minNode->year;
    
    // Set the minNode right's parent
    if (minNode->rightChild)
        minNode->parent->rightChild = minNode->parent;
    
    // Is the minNode directly attached to right side of the node.
    if (node->rightChild == minNode) {
        node->rightChild = minNode->rightChild;
        delete minNode;
        return;
    }
    
    // If not present directly on the right.
    minNode->parent->leftChild = minNode->rightChild;
    delete minNode;
}

void MovieTree::addMovieNode(int ranking, std::string title, int releaseYear, int quantity) {
    auto node = new MovieNode(ranking, title, releaseYear, quantity);
    if (!root) {
        // no root.
        root = node;
        return;
    }
    
    // string comparision uses std::lexicographical_compare.
    // So i can directly comapare titles.
    
    auto *temp = root;
    MovieNode* parent = nullptr;
    
    while(temp) {
        parent = temp;
        if (title > temp->title)
            temp = temp->rightChild;
        else
            temp = temp->leftChild;
    }
    
    // parent shouldn't be nullptr at this point.
    
    node->parent = parent;
    if (title > parent->title)
        parent->rightChild = node;
    else
        parent->leftChild = node;
}

void MovieTree::findMovie(std::string title) {
    auto foundMovie = search(title);
    if (!foundMovie) {
        //If movie not found in tree
        cout << "Movie not found." << endl;
    } else {
        cout << "Movie Info:" << endl;
        cout << "===========" << endl;
        cout << "Ranking:" << foundMovie->ranking << endl;
        cout << "Title:" << foundMovie->title << endl;
        cout << "Year:" << foundMovie->year << endl;
        cout << "Quantity:" << foundMovie->quantity << endl;
    }
}

void MovieTree::rentMovie(std::string title) {
    auto foundMovie = search(title);
    if (!foundMovie) {
        //If movie not found in tree
        cout << "Movie not found." << endl;
        return;
    }
    
    //If movie is in stock
    if (foundMovie->quantity > 0) {
        // rent the movie.
        foundMovie->quantity--;
    
        cout << "Movie has been rented." << endl;
        cout << "Movie Info:" << endl;
        cout << "===========" << endl;
        cout << "Ranking:" << foundMovie->ranking << endl;
        cout << "Title:" << foundMovie->title << endl;
        cout << "Year:" << foundMovie->year << endl;
        cout << "Quantity:" << foundMovie->quantity << endl;
    }
    
    // If movie quantity is zero, delete it from movie tree.
    if (foundMovie->quantity <= 0) {
        deleteMovieNode(foundMovie->title);
        // At this point foundMovie is invalid. Don't use foundMovie.
        foundMovie = nullptr;
    }
}

void MovieTree::DeleteAll(MovieNode * node) { //use this for the post-order traversal deletion of the tree
    if (!node) {
        // no node to delete.
        return;
    }
    
    DeleteAll(node->leftChild);
    DeleteAll(node->rightChild);
    
    //For all movies in tree
    cout << "Deleting: " << node->title << endl;
    
    delete node;
    node = nullptr;
}

void MovieTree::printMovieInventory(MovieNode * node) {
    if (!node) {
        return;
    }
    
    printMovieInventory(node->leftChild);
    
    // For all movies in tree
    cout << "Movie: " << node->title << " " << node->quantity << endl;
    
    printMovieInventory(node->rightChild);
}

void MovieTree::countMovieNodes(MovieNode *node, int *c) {
    if (!node) {
        // node is empty. nothing to count.
        return;
    }
    
    countMovieNodes(node->leftChild, c);
    (*c)++;
    countMovieNodes(node->rightChild, c);
}

MovieNode* MovieTree::search(std::string title) {
    return searchRecursive(root, title);
}

MovieNode* MovieTree::searchRecursive(MovieNode *node, std::string value) {
    if (!node) {
        return nullptr;
    }
    
    if (node->title == value) {
        return node;
    }
    
    if (value > node->title)
        return searchRecursive(node->rightChild, value);
    else
        return searchRecursive(node->leftChild, value);
}

MovieNode* MovieTree::treeMinimum(MovieNode *node) {
    if (!node) {
        return nullptr;
    }
    
    while(node->leftChild) {
        node = node->leftChild;
    }
    
    return node;
}
