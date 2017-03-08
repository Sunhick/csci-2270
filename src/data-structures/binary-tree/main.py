#!/usr/bin/python3

"""
Example of using binary tree

main file
"""

from BinaryTrees import BinaryTree

def main():
    bt = BinaryTree()
    values = [20, 9, 23, 8, 11, 55, 24, 27, 10, 12, 13, 21, 22, 56, 66, 57]
    for value in values:
        bt.AddValue(value)

    bt.InorderTraversal()
    print("===============")

    deletes = [8, 13, 24, 23, 20]
    for d in deletes:
        bt.DeleteValue(d)
        bt.InorderTraversal()
        print("----------")

if __name__ == '__main__':
    main()
