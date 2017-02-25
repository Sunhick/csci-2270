#!/usr/bin/python3

"""
Red black trees

Pythonic implementation of red black trees
"""

__author__ = "Sunil"
__email__ = "suba5417@colorado.edu"

from Node import RedNode, BlackNode
from Node import Color
from queue import *

class RedBlackTree(object):
    """
    Red black tree invariant:
        * Root should always be black.
        * Every node is either black / red.
        * No Red-Red Parent-child relation.
        * Every simple path from a node to a descendant leaf contains the same number of black nodes.
    """
    __root = None
    __count = 0
    def __init__(self):
        pass

    @property
    def Root(self):
        return self.__root

    @property
    def Count(self):
        return self.__count

    def insertNode(self, value):
        if not self.__root:
            # no root node. Create a black root node
            self.__root = BlackNode(value=value)
            self.__count += 1
            return

        # insert new red node into BST
        self.__count += 1
        parent = self.__root
        child = None
        while(parent):
            if parent.Value > value:
                if not parent.Left:
                    child = RedNode(value=value, parent=parent)
                    parent.Left = child
                    break;
                parent = parent.Left
            else:
                if not parent.Right:
                    child = RedNode(value=value, parent=parent)
                    parent.Right = child
                    break;
                parent = parent.Right

        self.__balanceTree(parent.Parent, parent, child)

    def inorderTraversal(self, node, callback):
        if not node:
            return
        self.inorderTraversal(node.Left, callback)
        callback(node)
        self.inorderTraversal(node.Right, callback)

    def preorderTraversal(self, node, callback):
        if not node:
            return
        callback(node)
        self.preorderTraversal(node.Left, callback)
        self.preorderTraversal(node.Right, callback)

    def postorderTraversal(self, node, callback):
        if not node:
            return
        self.postorderTraversal(node.Left, callback)
        self.postorderTraversal(node.Right, callback)
        callback(node)

    def dfs(self, root, callback):
        stack = []
        stack.append(root)
        while stack:
            node = stack.pop()
            if node.Right:
                stack.append(node.Right)
            if node.Left:
                stack.append(node.Left)
            callback(node)

    def bfs(self, root, callback):
        q = Queue()
        q.put(root)
        while not q.empty():
            node = q.get()
            if node.Left:
                q.put(node.Left)
            if node.Right:
                q.put(node.Right)
            callback(node)

    def deleteNode(self, value):
        pass

    def __validRedBlackTree(self):
        """
            Determine if a given tree is a valid Red black tree
        """
        pass

    def __recoloring(self, grandparent, parent):
        # If the parent's sibling is Red, then recolor
        if not grandparent:
            return

        sibling = grandparent.Right if grandparent.Left == parent else grandparent.Left
        if not sibling:
            # this shouldn't be called if no sibling exists! Rotation required
            return

        sibling.FlipColor()
        parent.FlipColor()
        grandparent.FlipColor()

        self.__recoloring(grandparent.Parent, grandparent)

    def __rotate(self, grandparent, parent, child):
        if (not grandparent):
            return

        leftParent = grandparent.Left == parent
        leftChild = parent.Left == child
        uncle = grandparent.Right if leftParent else grandparent.Left

        # case-1: Left Left case
        if (leftParent and leftChild):
            grandgrandParent = grandparent.Parent
            parentRight = parent.Right
            parent.Right = grandparent
            grandparent.Parent = parent
            grandparent.Left = parentRight
            parentRight.Parent = grandparent
            parent.FlipColor()
            grandparent.FlipColor()

            if (grandgrandParent):
                if grandgrandParent.Left == grandparent:
                    grandgrandParent.Left = parent
                else:
                    grandgrandParent.Right = parent
                parent.Parent = grandgrandParent
                self.__balanceTree(parent.Parent.Parent, parent.Parent, parent)
            return
        
        # case-2: Left Right case
        if (leftParent and not leftChild):
            parent.Right = child.Left
            child.Left.Parent = parent
            child.Left = parent
            child.Parent = parent.Parent
            parent.Parent = child
            self.__balanceTree(chid.Parent,child, parent)
            return

        # case-3: Right Right case
        if (not leftParent and not leftChild):
            grandgrandParent = grandparent.Parent
            parentLeft = parent.Left
            parent.Left = grandparent
            grandparent.Parent = parent
            grandparent.Right = parentLeft
            parentLeft.Parent = grandparent
            parent.FlipColor()
            grandparent.FlipColor()

            if (grandgrandParent):
                if grandgrandParent.Left == grandparent:
                    grandgrandParent.Left = parent
                else:
                    grandgrandParent.Right = parent
                parent.Parent = grandgrandParent
                self.__balanceTree(parent.Parent.Parent, parent.Parent, parent)
            return

        # case-4: Right Left case
        if (not leftParent and leftChild):
            parent.Left = child.Right
            child.Right.Parent = parent
            child.Right = parent
            child.Parent = parent.Parent
            parent.Parent = child
            self.__balanceTree(child.Parent,child, parent)
            return

    def __balanceTree(self, grandparent, parent, child):
        """
        case 1: If Parent and it's sibling are Red. Then recolor and check.

        case 2: If the Parent and it's sibling are Black/not present, Then rotate and recolor
        """
        if (not grandparent):
            return

        uncle = grandparent.Right
        if (uncle and uncle.Color == parent.Color):
            return self.__recoloring(grandparent, parent)

        # If the uncle is black then rotate/recolor accordingly
        return self.__rotate(grandparent, parent, child)

    def search(self, value):
        pass

    def prune(self):
        pass

    def graft(self):
        pass