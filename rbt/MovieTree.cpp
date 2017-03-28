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

MovieTree::MovieTree() {
    // nil nodes are treated as black nodes.
    nil = new MovieNode;
    nil->isRed = false;
    nil->leftChild = nil;
    nil->rightChild = nil;
    root = nil;
}

MovieTree::~MovieTree() {
    // avoid double deletion of nil node when tree isn't constructed.
    if (root == nil) {
        delete nil;
        root = nil = nullptr;
        return;
    }
    
    if (root)
        DeleteAll(root);
    if (nil)
        delete nil;
}

// Returns 0 if the tree is invalid, otherwise returns the black node height.
int MovieTree::rbValid(MovieNode* node) {
    int lh = 0;
    int rh = 0;
    
    // If we are at a nil node just return 1
    if (node == nil) {
        return 1;
    }
    
    // First check for consecutive red links.
    if (node->isRed) {
        if(node->leftChild->isRed || node->rightChild->isRed) {
            cout << "This tree contains a red violation" << endl;
            return 0;
        }
    }
    
    // Check for valid binary search tree.
    if ((node->leftChild != nil && node->leftChild->title.compare(node->title) > 0) ||
        (node->rightChild != nil && node->rightChild->title.compare(node->title) < 0)) {
        cout << "This tree contains a binary tree violation" << endl;
        return 0;
    }
    
    // Deteremine the height of let and right children.
    lh = rbValid(node->leftChild);
    rh = rbValid(node->rightChild);
    
    // black height mismatch
    if (lh != 0 && rh != 0 && lh != rh) {
        cout << "This tree contains a black height violation" << endl;
        return 0;
    }
    
    // If neither height is zero, incrament if it if black.
    if (lh != 0 && rh != 0) {
        if (node->isRed)
            return lh;
        return lh+1;
    }
    
    return 0;
}

void MovieTree::printMovieInventory() {
    printMovieInventory(root);
}

int MovieTree::countMovieNodes() {
    return countMovieNodes(root);
}

void MovieTree::deleteMovieNode(std::string title) {
    auto found = searchMovieTree(root, title);
    
    if (found == nil) {
        //If movie not found in tree
        cout << "Movie not found." << endl;
        return;
    }
    
    rbDelete(found);
    
    if(!rbValid(root)) {
        // flag if the tree isn't valid.
        throw runtime_error("invalid rb tree deletion!");
    }
}

void MovieTree::addMovieNode(int ranking, std::string title, int releaseYear, int quantity) {
    auto node = new MovieNode(ranking, title, releaseYear, quantity);
    
    // always add a red node.
    node->isRed = true;
    node->parent = node->leftChild = node->rightChild = nil;
    
    if (root == nil) {
        // no root.
        root = node;
        root->isRed = false;
        return;
    }
    
    // string comparision uses std::lexicographical_compare.
    // So i can directly comapare titles.
    
    auto *temp = root;
    MovieNode* parent = nullptr;
    
    while(temp != nil) {
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
    
    rbAddFixup(node);
    
    if(!rbValid(root)) {
        // flag if the tree isn't valid.
        throw runtime_error("invalid rb tree addition!");
    }
}

void MovieTree::findMovie(std::string title) {
    auto foundMovie = searchMovieTree(root, title);
    
    if (foundMovie == nil) {
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
    auto foundMovie = searchMovieTree(root, title);
    if (foundMovie == nil) {
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
        rbDelete(foundMovie);
        //deleteMovieNode(foundMovie->title);
        // At this point foundMovie is invalid. Don't use foundMovie.
        foundMovie = nil;
    }
}

bool MovieTree::isValid() {
    return rbValid(root);
}

int MovieTree::countLongestPath() {
    return countLongestPath(root);
}

void MovieTree::DeleteAll(MovieNode* node) {
    //use this for the post-order traversal deletion of the tree
    if (node == nil) {
        // no node to delete.
        return;
    }
    
    DeleteAll(node->leftChild);
    DeleteAll(node->rightChild);
    
    //For all movies in tree
    cout << "Deleting: " << node->title << endl;
    
    delete node;
    node = nil;
}

void MovieTree::printMovieInventory(MovieNode* node) {
    if (node == nil) {
        return;
    }
    
    printMovieInventory(node->leftChild);
    
    // For all movies in tree
    cout << "Movie: " << node->title << " " << node->quantity << endl;
    
    printMovieInventory(node->rightChild);
}

void MovieTree::rbAddFixup(MovieNode* x) {
    // called after insert to fix tree
    while (true) {
        // loop invarient: node is red.
        // we don't want two consecutive nodes (node and it's parent) to be red.
        
        /*
            notation used in rb tree representation in comments.
                g  = black grand parent
                p  = black parent
                u  = black uncle
         
                X  = newly inserted red node
                G  = red grand parent
                P  = red parent
                U  = red uncle
         
            notation used in code:
                g = grand parent
                p = parent
                u = uncle
                x = node newly inserted.
         */
        auto p = x->parent;

        // if node's parent is black or null node(black). then we're done.
        if (p == nil || !p->isRed) {
            break;
        }
        
        auto g = p->parent;
        auto is_p_left_of_g = (g->leftChild == p);
        auto u = is_p_left_of_g ? g->rightChild : g->leftChild;
        
        // treat null node as a black node.
        auto u_is_black =  !u->isRed;
        
        /* case 1: uncle is red.
            fix: recolor parent, grand-parent and uncle.
         
                      ...                                        ...
                      /                                          /
                     g             recolor (g, p, u)            G
                   /   \          ------------------->        /   \
                  P     U                                    p     u
                 / \   / \                                  / \   / \
                X                                          X
                  ...                                        ...
                    \                                          \
                     g             recolor (g, p, u)            G
                   /   \          ------------------->        /   \
                  U     P                                    u     p
                 / \   / \                                  / \   / \
                          X                                          X
         */
        auto u_is_red = !u_is_black;
        
        if (u_is_red) {
            g->isRed = true;
            p->isRed = false;
            
            if (u != nil) {
                u->isRed = false;
            }
            
            // continue recoloring up the tree until rbtree properties are fixed.
            x = g;
            continue;
        }
        
        /* case 2: uncle is black (node is internal. falls within uncle and parent subtree).
            fix: rotate around parent. This rotation leads to case 3.
         
                    ...                                             ...
                    /                                               /
                   g                                               g
                 /   \           left rotate around p            /   \
                P     u        ----------------------->         X     u
               / \   / \                                       / \   / \
                  X                                           P
         
                ...                                            ...
                  \                                              \
                  g                                               g
                /   \          right rotate around p            /   \
               u     P        ----------------------->         u     X
              / \   / \                                       / \   / \
                   X                                                   P
         */
        auto is_x_right_of_p = (p->rightChild == x);
        auto x_is_internal = (is_p_left_of_g && is_x_right_of_p) || (!is_p_left_of_g && !is_x_right_of_p);
        
        if (u_is_black && x_is_internal) {
            
            if (is_p_left_of_g && is_x_right_of_p)
                leftRotate(p);
            else
                rightRotate(p);
            
            // after left / right rotate, P takes the place of X
            x = p;
            continue;
        }
        
        /* case 3: uncle is black (node is external. falls outside of uncle and parent's subtree)
            fix: rotate around grand-parent and swap colors of grand-parent & parent.
         
                    ...                                             ...
                    /                                               /
                   g                                               p
                 /   \          right rotate around g            /   \
                P     u       -------------------------->       X     G
               / \   / \        swap color of (p, g)                 / \
              X   a                                                 a   u
                                                                       / \
         
              ...                                            ...
                \                                              \
                 g                                              p
               /   \          left rotate around g            /   \
              u     P       -------------------------->      G     X
             / \   / \        swap color of (p, g)          / \
                  a   X                                    u   a
                                                          / \
         */
        // I'm hard coding to true, because if none of the above cases are satisfied, It
        // has to be a case-3 and has to be external node.
        auto is_x_left_of_p = (p->leftChild == x);
        auto x_is_external = true;
        
        if (u_is_black && x_is_external) {
            if (is_p_left_of_g && is_x_left_of_p)
                rightRotate(g);
            else
                leftRotate(g);
            
            // swap the color of (parent, grand-parent) after rotation.
            g->isRed ^= p->isRed;
            p->isRed ^= g->isRed;
            g->isRed ^= p->isRed;
        }
    }
    
    // in case if root's color is changed by case-1.
    // reset it's color to black.
    root->isRed = false;
}

void MovieTree::leftRotate(MovieNode* x) {
    //rotate the tree left with x as the root of the rotation
    /*
                x                                          y
               / \          left rotate around x          / \
              a   y       ------------------------>      x   c
                 / \                                    / \
                b   c                                  a   b
    */
    auto y = x->rightChild;
    
    // get left subtree of y if available.
    // otherwise set it to nullptr.
    auto b = y->leftChild;
    
    // no need to get c, as it stays unaffected by left rotation.
    
    // turn y's left subtree into a x's right subtree.
    x->rightChild = b;
    if (b != nil) {
        b->parent = x;
    }
    
    // set parent of y to x's parent.
    y->parent = x->parent;
    
    // if x doesn't have a parent, make y as root.
    if (x->parent == nil) {
        root = y;
    }
    // parent is not null, see if x is to left/right of parent.
    else if (x->parent->leftChild == x) {
        x->parent->leftChild = y;
    }
    else {
        x->parent->rightChild = y;
    }
    
    y->leftChild = x;
    x->parent = y;
}
void MovieTree::rbDelete(MovieNode* z) {
    //delete a node. Call this from deleteMovieNode, the actual delete functionality happens here.
    MovieNode * y = z;
    MovieNode * x = nil;
    bool yOrigColor = y->isRed;
    
    if (z->leftChild == nil)
    {
        x = z->rightChild;
        rbTransplant(z,z->rightChild);
    }
    else if (z->rightChild == nil)
    {
        x = z->leftChild;
        rbTransplant(z,z->leftChild);
    }
    else
    {
        // y = tree min of right
        y = z->rightChild;
        while (y->leftChild != nil) {
            y = y->leftChild ;
        }
        
        yOrigColor = y->isRed;
        x = y->rightChild;
        
        if (y->parent == z) {
            x->parent = y;
        } else {
            rbTransplant(y,y->rightChild);
            y->rightChild = z->rightChild;
            y->rightChild->parent = y;
        }
        
        rbTransplant(z,y);
        y->leftChild = z->leftChild;
        y->leftChild->parent = y;
        y->isRed = z->isRed;
    }
    
    // Actually the node.
    delete z;
    
    // Check if we need to now fix the tree.
    if (yOrigColor == false)
        rbDeleteFixup(x);
}

void MovieTree::rightRotate(MovieNode* y) {
    //rotate the tree right with x as the root of the rotation
    /*
                 y                                        x
                / \        right rotate around y         / \
               x   c     ----------------------->       a   y
              / \                                          / \
             a   b                                        b   c
         
    */
    auto x = y->leftChild;
    
    // get right subtree of x if available.
    // otherwise set it to nullptr.
    auto b = x->rightChild;
    
    // turn x's right subtree into a y's left subtree.
    y->leftChild = b;
    
    if (b != nil) {
        b->parent = y;
    }
    
    // set parent of x to y's parent.
    x->parent = y->parent;
    
    // if y doesn't have a parent, make x as root.
    if (y->parent == nil) {
        root = x;
    }
    // parent is not null, see if y is to left/right of parent.
    else if (y->parent->leftChild == y) {
        y->parent->leftChild = x;
    }
    else {
        y->parent->rightChild = x;
    }
    
    x->rightChild = y;
    y->parent = x;
}

void MovieTree::rbDeleteFixup(MovieNode* node) {
    //called after delete to fix the tree
    MovieNode* w = NULL;
    
    // Now we restore the red-black properties.
    while ((node != root) && (node->isRed == false))
    {
        // If we are a left child
        if (node == node->parent->leftChild) {
            w = node->parent->rightChild;
            
            // If helper is red
            if (w->isRed) {
                w->isRed = false;
                node->parent->isRed = true;
                leftRotate(node->parent);
                w = node->parent->rightChild;
            }
            
            // If helper's children are both black
            if (w->leftChild->isRed == false && w->rightChild->isRed == false) {
                w->isRed = true;
                node = node->parent;
            }
            else {
                if (w->rightChild->isRed == false) {
                    // case 3
                    w->leftChild->isRed = false;
                    w->isRed = true;
                    rightRotate(w);
                    w = node->parent->rightChild;
                }
                // case 4
                w->isRed = node->parent->isRed;
                node->parent->isRed = false;
                w->rightChild->isRed = false;
                leftRotate(node->parent);
                node = root;
            }
        }
        
        // If we are a right child
        else {
            
            // helper is the left child
            w = node->parent->leftChild;
            // If helper is red
            if (w->isRed) {
                w->isRed = false;
                node->parent->isRed = true;
                rightRotate(node->parent);
                w = node->parent->leftChild;
            }
            
            // If helper's children are both black
            if (w->leftChild->isRed == false && w->rightChild->isRed == false) {
                w->isRed = true;
                node = node->parent;
            }
            
            else {
                if (w->leftChild->isRed == false) {
                    // case 3
                    w->rightChild->isRed = false;
                    w->isRed = true;
                    leftRotate(w);
                    w = node->parent->leftChild;
                }
                
                // case 4
                w->isRed = node->parent->isRed;
                node->parent->isRed = false;
                w->leftChild->isRed = false;
                rightRotate(node->parent);
                node = root;
            }
        }
    }
    
    node->isRed = false;
}

void MovieTree::rbTransplant(MovieNode * u, MovieNode * v) {
    //replace node u in tree with node v. Your solution doesn't necessarily need to use this method
    if (u->parent == nil)
        root = v;
    else if (u == u->parent->leftChild)
        u->parent->leftChild = v;
    else
        u->parent->rightChild = v;
    
    v->parent = u->parent;
}

int MovieTree::countMovieNodes(MovieNode* node) {
    //number of unique titles in the tree
    
    // root node (1) + # of nodes on left subtree + # of nodes on right subtree.
    return (
            (node == nil) ? 0 : (1 + countMovieNodes(node->leftChild) + countMovieNodes(node->rightChild))
            );
}

int MovieTree::countLongestPath(MovieNode* node) {
    //longest path from node to a leaf node in the tree
    
    return (
            (node == nil) ? 0 : (1 + max(countLongestPath(node->leftChild), countLongestPath(node->rightChild)))
            );
}

MovieNode* MovieTree::searchMovieTree(MovieNode* node, std::string title) {
    if (node == nil) {
        return nullptr;
    }
    
    if (node->title == title) {
        return node;
    }
    
    if (title > node->title)
        return searchMovieTree(node->rightChild, title);
    
    return searchMovieTree(node->leftChild, title);
}
