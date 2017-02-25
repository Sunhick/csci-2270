#!/usr/bin/python3

"""
Example of using Red Black trees

main file
"""

from RedBlackTree import RedBlackTree

def main():
    tree = RedBlackTree()
    tree.insertNode(25)
    tree.insertNode(15)
    tree.insertNode(50)
    tree.insertNode(10)
    tree.insertNode(22)
    tree.insertNode(35)
    tree.insertNode(70)
    tree.insertNode(4)
    tree.insertNode(12)
    tree.insertNode(18)
    tree.insertNode(24)
    tree.insertNode(31)
    tree.insertNode(44)
    tree.insertNode(66)
    tree.insertNode(90)

    print("======In Order========")
    tree.inorderTraversal(tree.Root, lambda node: print(node.Value, node.Color))
    
    print("======Pre Order========")
    tree.preorderTraversal(tree.Root, lambda node: print(node.Value, node.Color))

    print("======Post Order========")
    tree.postorderTraversal(tree.Root, lambda node: print(node.Value, node.Color))

    print("========DFS===========")
    tree.dfs(tree.Root, lambda node: print(node.Value, node.Color))

    print("========BFS===========")
    tree.bfs(tree.Root, lambda node: print(node.Value, node.Color))

if __name__ == '__main__':
    main()
