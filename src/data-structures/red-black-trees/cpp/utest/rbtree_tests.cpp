#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

#include "gtest/gtest.h"

// redefine class, private & protected to get access to
// private and protected members of rbtree & rbnode.
#define class struct
#define private public
#define protected public

#include "../rbtree.hpp"
#include "../rbnode.hpp"

#undef class
#undef private
#undef protected

using namespace std;

// Redirect the cout to a string
struct cout_redirect {
  cout_redirect(std::streambuf* new_buffer) 
    : old( std::cout.rdbuf(new_buffer))
  {
  }

  ~cout_redirect() {
    std::cout.rdbuf(old);
  }

private:
  std::streambuf* old;
};

class rbtree_tests : public ::testing::Test {
public:
    // red black trees
    rbtree* rbt;
    
    rbtree_tests() {
        rbt = new rbtree();
    }
    
    ~rbtree_tests() {
        delete rbt;
    }
};

TEST_F(rbtree_tests, test_empty) {
    EXPECT_TRUE(rbt->root == nullptr) << "root should be null!";
}

TEST_F(rbtree_tests, test_rbtree_invalid_1) {
    rbt->root = new rbnode(56, rbcolor::red);
    EXPECT_FALSE(rbt->is_valid_rbtree()) << "tree with red root should be invalid!";
}

TEST_F(rbtree_tests, test_rbtree_invalid_2) {
    auto root = new rbnode(7, rbcolor::black);
    auto n3 = new rbnode(3, rbcolor::red, root);
    auto n18 = new rbnode(18, rbcolor::black, root);
    auto n1 = new rbnode(1, rbcolor::black, n3);
    auto n45 = new rbnode(45, rbcolor::black, n18);
    auto n2 = new rbnode(2, rbcolor::black, n1);
    
    root->left = n3;
    root->right = n18;
    n18->right = n45;
    n3->left = n1;
    n1->right = n2;
    
    rbt->root = root;
    EXPECT_FALSE(rbt->is_valid_rbtree());
}

TEST_F(rbtree_tests, test_rbtree_valid_1) {
    // build a red black tree.
    auto root = new rbnode(45, rbcolor::black);
    
    auto r1 = new rbnode(25);
    r1->parent = root;
    
    auto r2 = new rbnode(60);
    r2->parent = root;
    
    root->left = r1;
    root->right = r2;
    
    rbt->root = root;
    EXPECT_TRUE(rbt->is_valid_rbtree());
}

TEST_F(rbtree_tests, test_rbtree_valid_2) {
    auto root = new rbnode(10, rbcolor::black);
    auto n7 = new rbnode(7, rbcolor::black, root);
    auto n19 = new rbnode(19, rbcolor::red, root);
    auto n13 = new rbnode(13, rbcolor::black, n19);
    auto n23 = new rbnode(23, rbcolor::black, n19);
    
    root->left = n7;
    root->right = n19;
    n19->left = n13;
    n19->right = n23;
    
    rbt->root = root;
    EXPECT_TRUE(rbt->is_valid_rbtree());
}

TEST_F(rbtree_tests, test_rbtree_insert) {
    // generated using visualization tool: https://www.cs.usfca.edu/~galles/visualization/RedBlack.html
    vector<string> expected = {
        "0(black)\n",
        "0(black)\n1(red)\n",
        "0(red)\n1(black)\n2(red)\n",
        "0(black)\n1(black)\n2(black)\n3(red)\n",
        "0(black)\n1(black)\n2(red)\n3(black)\n4(red)\n",
        "0(black)\n1(black)\n2(black)\n3(red)\n4(black)\n5(red)\n",
        "0(black)\n1(black)\n2(black)\n3(red)\n4(red)\n5(black)\n6(red)\n",
        "0(black)\n1(red)\n2(black)\n3(black)\n4(black)\n5(red)\n6(black)\n7(red)\n",
        "0(black)\n1(red)\n2(black)\n3(black)\n4(black)\n5(red)\n6(red)\n7(black)\n8(red)\n",
        "0(black)\n1(black)\n2(black)\n3(black)\n4(black)\n5(black)\n6(black)\n7(red)\n8(black)\n9(red)\n"
    };
    
    for (int i = 0; i < expected.size(); i++) {
        auto n = i+1;
        rbt->insert(i);
        
        stringstream buffer; {
            cout_redirect activate(buffer.rdbuf());
            rbt->inorder();
        }
        string got = buffer.str();
        
        EXPECT_TRUE(expected[i] == got) << "insert of " << i << " is incorrect!";
        
        // max heigth of rb tree <= 2 * log(n+1)
        EXPECT_TRUE(rbt->depth() < 2 * ceil(log2(n+1))) << "depth of rb tree is incorrect!";
        
    }
}

TEST_F(rbtree_tests, test_rbtree_remove) {
    
}

TEST_F(rbtree_tests, test_rbtree_remove_all) {
    rbt->remove_all(rbt->root);
    EXPECT_TRUE(rbt->root == nullptr);
    EXPECT_TRUE(rbt->depth() == 0) << "depth of empty rb tree should be zero!";
}

TEST_F(rbtree_tests, test_left_rotate) {
    /*
          x                                          y
         / \          left rotate around x          / \
        a   y       ------------------------>      x   c
           / \                                    / \
          b   c                                  a   b
     */
    
    auto x = new rbnode(50, rbcolor::black);
    auto y = new rbnode(60, rbcolor::red, x);
    auto a = new rbnode(25, rbcolor::black, x);
    auto b = new rbnode(55, rbcolor::black, y);
    auto c = new rbnode(70, rbcolor::black, y);
    
    x->left = a;
    x->right = y;
    y->right = c;
    y->left  = b;
    
    rbt->root = x;
    rbt->left_rotate(x);
    
    stringstream buffer; {
        cout_redirect activate(buffer.rdbuf());
        rbt->inorder();
    }
    
    string expected = "25(black)\n50(black)\n55(black)\n60(red)\n70(black)\n";
    string got = buffer.str();
    
    EXPECT_TRUE(expected == got) << "left rotation is incorrect!";
    EXPECT_TRUE(rbt->depth() == 3) << "left rotation is of incorrect depth!";
}

TEST_F(rbtree_tests, test_right_rotate) {
    /*
             y                                        x
            / \        right rotate around y         / \
           x   c     ----------------------->       a   y
          / \                                          / \
         a   b                                        b   c
     
     */
    
    auto y = new rbnode(50, rbcolor::black);
    auto x = new rbnode(25, rbcolor::red, y);
    auto a = new rbnode(10, rbcolor::black, x);
    auto b = new rbnode(30, rbcolor::black, x);
    auto c = new rbnode(60, rbcolor::black);
    
    x->left = a;
    x->right = b;
    y->right = c;
    y->left  = x;
    
    rbt->root = y;
    rbt->right_rotate(y);
    
    stringstream buffer; {
        cout_redirect activate(buffer.rdbuf());
        rbt->inorder();
    }
    
    string expected = "10(black)\n25(red)\n30(black)\n50(black)\n60(black)\n";
    string got = buffer.str();
    
    EXPECT_TRUE(expected == got) << "right rotation is incorrect.";
    EXPECT_TRUE(rbt->depth() == 3) << "right rotation is of incorrect depth";
}
