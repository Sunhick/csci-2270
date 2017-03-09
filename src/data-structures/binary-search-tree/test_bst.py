#!/usr/bin/python3

"""

unit testing of binary search trees
"""
import sys
import unittest

from io import TextIOWrapper, BytesIO
from BinarySearchTrees import BinarySearchTree

class Test_BST(unittest.TestCase):
    """
    test BST creation, deletion and traversals
    """

    bst = None
    values = expected_inorder = expected_preorder = expected_postorder = list()

    def setUp(self):
        self.values             = [5, 2, 18, -4, 3, 21, 19, 25]
        self.expected_inorder   = [-4, 2, 3, 5, 18, 19, 21, 25]
        self.expected_preorder  = [5, 2, -4, 3, 18, 21, 19, 25]
        self.expected_postorder = [-4, 3, 2, 19, 25, 21, 18, 5]
    
        self.bst = BinarySearchTree()
        self.populateBST()

    def teatDown(self):
        del self.bst
        del self.values
        del self.expected_inorder
        del self.expected_preorder
        del self.expected_postorder

    def populateBST(self):
        for value in self.values:
            self.bst.AddValue(value)

    def redirectPrint(self):
        # redirect the print lines to a string buffer
        sys.stdout = TextIOWrapper(BytesIO(), sys.stdout.encoding)

    def restorePrint(self):
        # read from the begining
        sys.stdout.seek(0)
        out = sys.stdout.read()
        sys.stdout.close()

        # restore print to console output
        sys.stdout = sys.__stdout__
        return out

    def test_creation(self):
        self.assertIsNotNone(self.bst.Root, "Root is null")
        self.assertEqual(self.bst.Root.Value, self.values[0],
                         'Root value should be {0}'.format(self.values[0]))

    def test_inorder(self):
        self.redirectPrint()
        inorder = self.bst.InorderTraversal()
        output = self.restorePrint()
        got = list(map(int, output.strip().split('\n')))
        self.assertEqual(got, self.expected_inorder, 'Inorder traversal is incorrect')

    def test_preorder(self):
        self.redirectPrint()
        inorder = self.bst.PreorderTraversal()
        output = self.restorePrint()
        got = list(map(int, output.strip().split('\n')))
        self.assertEqual(got, self.expected_preorder, 'Preorder traversal is incorrect')

    def test_postorder(self):
        self.redirectPrint()
        inorder = self.bst.PostorderTraversal()
        output = self.restorePrint()
        got = list(map(int, output.strip().split('\n')))
        self.assertEqual(got, self.expected_postorder, 'Postorder traversal is incorrect')

    def test_deletecase1(self):
        value = 19
        self.expected_inorder.remove(value)
        self.bst.DeleteValue(value)

        self.redirectPrint()
        inorder = self.bst.InorderTraversal()
        got = list(map(int, self.restorePrint().strip().split('\n')))
        self.assertEqual(got, self.expected_inorder, 'Deletion of {0} is incorrect!'.format(value))
        

    def test_deletecase2(self):
        value = 18
        self.expected_inorder.remove(value)
        self.bst.DeleteValue(value)

        self.redirectPrint()
        inorder = self.bst.InorderTraversal()
        got = list(map(int, self.restorePrint().strip().split('\n')))
        self.assertEqual(got, self.expected_inorder, 'Deletion of {0} is incorrect!'.format(value))

    def test_deletecase3(self):
        value = 21
        self.expected_inorder.remove(value)
        self.bst.DeleteValue(value)

        self.redirectPrint()
        inorder = self.bst.InorderTraversal()
        got = list(map(int, self.restorePrint().strip().split('\n')))
        self.assertEqual(got, self.expected_inorder, 'Deletion of {0} is incorrect!'.format(value))

    def test_deleteRoot(self):
        value = self.values[0]
        self.expected_inorder.remove(value)
        self.bst.DeleteValue(value)

        self.redirectPrint()
        inorder = self.bst.InorderTraversal()
        got = list(map(int, self.restorePrint().strip().split('\n')))
        self.assertEqual(got, self.expected_inorder, 'Deletion of root node {0} is incorrect!'.format(value))

    def test_delete_allNodes_oneByOne(self):
        for value in self.values:
            print("deleting node = ", value)
            self.expected_inorder.remove(value)
            self.bst.DeleteValue(value)
            self.redirectPrint()
            inorder = self.bst.InorderTraversal()
            got = list(map(int, self.restorePrint().strip().split('\n')))
            print("got = ",got)
            self.assertEqual(got, self.expected_inorder, 'Deletion of node {0} is incorrect!'.format(value))

if __name__ == "__main__":
    unittest.main()
