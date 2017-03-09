#!/usr/bin/python3

"""
Example of using binary search tree

main file
"""

__author__ = "Sunil"
__email__ = "suba5417@colorado.edu"

from BinarySearchTree import BinarySearchTree

def main():
    bst = BinarySearchTree()
    values = [20, 9, 23, 8, 11, 55, 24, 27, 10, 12, 13, 21, 22, 56, 66, 57]
    for value in values:
        bst.AddValue(value)

    bst.InorderTraversal()
    print("===============")

    deletes = [8, 13, 24, 23, 20]
    for d in deletes:
        bst.DeleteValue(d)
        bst.InorderTraversal()
        print("----------")

    bst = BinarySearchTree()
    values = [5, 2, 18, -4, 3, 21, 19, 25]
    for e in values:
        bst.AddValue(e)

    for e in values:
        print("deleting", e)
        bst.DeleteValue(e)
        bst.InorderTraversal()
        print("-------------")

if __name__ == '__main__':
    main()
