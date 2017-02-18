#!/usr/bin/python3

"""
Example of using Red Black trees

main file
"""

from RedBlackTree import RedBlackTree

def main():
    trees = RedBlackTree()
    trees.insertNode(25)
    trees.insertNode(15)
    trees.insertNode(50)
    trees.insertNode(10)
    trees.insertNode(22)
    trees.insertNode(35)
    trees.insertNode(70)
    trees.insertNode(4)
    trees.insertNode(12)
    trees.insertNode(18)
    trees.insertNode(24)
    trees.insertNode(31)
    trees.insertNode(44)
    trees.insertNode(66)
    trees.insertNode(90)

    print("======in order========")
    trees.inorderTraversal(trees.Root, lambda x: print(x))
    
    print("======pre order========")
    trees.preorderTraversal(trees.Root, lambda x: print(x))

    print("======post order========")
    trees.postorderTraversal(trees.Root, lambda x: print(x))

if __name__ == '__main__':
    main()
