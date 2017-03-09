#!/usr/bin/python3

"""
Node definition

Pythonic implementation of binary search trees
"""

from Node import Node

class BinarySearchTree(object):
    """
    Binary search tree class
    """
    # entry point to the tree.
    __root = None

    @property
    def Root(self):
        return self.__root    

    def __init__(self):
        __root = None

    def AddValue(self, value):
        # create a new node and call add node
        self.AddNode(Node(value))

    def AddNode(self, node):
        if not self.__root:
            self.__root = node
            return
        self.__addNode(node, self.__root)

    def __addNode(self, node, root):
        if node.Value > root.Value:
            # Node has to be added to right
            if root.Right is None:
                root.Right = node
                node.Parent = root
            else:
                self.__addNode(node, root.Right)
        if node.Value < root.Value:
            # node goes to the left
            if root.Left is None:
                root.Left = node
                node.Parent = root
            else:
                self.__addNode(node, root.Left)

    def DeleteValue(self, value):
        node = self.SearchValue(value, self.__root)
        if not node:
            # node with value not found.
            return

        # node to be deleted.
        self.__deleteNode(node)

    def __deleteNode(self, node):
        # case 1: node has no children.
        if not node.Left and not node.Right:
            # check if parent is availble. 
            if node.Parent:
                # check where the node is present relative to it's parent.
                if node.Parent.Left == node:
                    node.Parent.Left = None
                else:
                    node.Parent.Right = None
            else:
                # If not, then it's a root. If it's root with no left/ right
                # child, then delete it.
                self.__root = None
            del node
            return

        # case 2: node has only 1 child
        if node.Left and not node.Right:
            node.Left.Parent = node.Parent
            # see if there's a parent.
            if node.Parent:
                if node.Parent.Left == node:
                    node.Parent.Left = node.Left
                else:
                    node.Parent.Right = node.Left
            else:
                # root with only left child.
                self.__root = node.Left
            del node
            return

        if node.Right and not node.Left:
            node.Right.Parent = node.Parent
            # check if parent is available.
            if node.Parent:
                if node.Parent.Left == node:
                    node.Parent.Left = node.Right
                else :
                    node.Parent.Right = node.Right
            else:
                # Root node with only right child
                self.__root = node.Right
            del node
            return

        # case 3: node has both left and right child
        # pick the min value from the right subtree
        minNode = self.__treeMinimum(node.Right)

        # It would be easier to copy value from minNode to node, 
        # instead of swapping the minNode with node and update a bunch of links.
        node.Value = minNode.Value
        
        # Is the minNode directly attached to right side of the node.
        if node.Right == minNode:
            node.Right = minNode.Right
            del minNode
            return
        # If not present directly on the right.
        minNode.Parent.Left = minNode.Right
        del minNode

    def __treeMinimum(self, node):
        # To pick minimum value from a tree, go to the extreme left.
        while node.Left:
            node = node.Left

        return node

    def SearchValue(self, value, root):
        if root is None:
            return None
        if value == root.Value:
            return root
        if value > root.Value:
            return self.SearchValue(value, root.Right)
        # value  < root.value
        return self.SearchValue(value, root.Left)

    def InorderTraversal(self):
        self.__inorderTraversal(self.__root)

    def PreorderTraversal(self):
        self.__preorderTraversal(self.__root)

    def PostorderTraversal(self):
        self.__postorderTraversal(self.__root)

    def __inorderTraversal(self, root):
        if not root:
            return

        if root.Left:
            self.__inorderTraversal(root.Left)
        
        print(root.Value)
        
        if root.Right:
            self.__inorderTraversal(root.Right)

    def __preorderTraversal(self, root):
        if not root:
            return

        print(root.Value)

        if root.Left:
            self.__preorderTraversal(root.Left)
        
        if root.Right:
            self.__preorderTraversal(root.Right)

    def __postorderTraversal(self, root):
        if not root:
            return

        if root.Left:
            self.__postorderTraversal(root.Left)
        
        if root.Right:
            self.__postorderTraversal(root.Right)

        print(root.Value)
