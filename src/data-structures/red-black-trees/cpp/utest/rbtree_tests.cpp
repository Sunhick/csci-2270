#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <iostream>
#include <vector>
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
    EXPECT_TRUE(rbt->root == nullptr) << "root should be null";
}

TEST_F(rbtree_tests, test_rbtree_invalid) {
    rbt->root = new rbnode(56, rbcolor::red);
    EXPECT_FALSE(rbt->is_valid_rbtree()) << "tree with red root is invalid";
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
    
}

TEST_F(rbtree_tests, test_rbtree_remove) {
    
}

TEST_F(rbtree_tests, test_rbtree_remove_all) {
    
}
