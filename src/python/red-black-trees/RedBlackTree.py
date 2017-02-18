#!/usr/bin/python3

"""
Red black trees

Pythonic implementation of red black trees
"""

__author__ = "Sunil"
__email__ = "suba5417@colorado.edu"

from Node import Node
from Node import Color
from queue import *

class RedBlackTree(object):
    __root = None
    def __init__(self):
        pass

    @property
    def Root(self):
        return self.__root

    def insertNode(self, value):
        if not self.__root:
            self.__root = Node(value)
            return

        # insert node into BST
        temp = self.__root
        while(temp):
            if temp.Value > value:
                if not temp.Left:
                    temp.Left = Node(value=value)
                    break;
                temp = temp.Left
            else:
                if not temp.Right:
                    temp.Right = Node(value)
                    break;
                temp = temp.Right

        self.__balanceTree()

    def inorderTraversal(self, node, func):
        if not node:
            return
        self.inorderTraversal(node.Left, func)
        func(node)
        self.inorderTraversal(node.Right, func)

    def preorderTraversal(self, node, func):
        if not node:
            return
        func(node)
        self.preorderTraversal(node.Left, func)
        self.preorderTraversal(node.Right, func)

    def postorderTraversal(self, node, func):
        if not node:
            return
        self.postorderTraversal(node.Left, func)
        self.postorderTraversal(node.Right, func)
        func(node)

    def dfs(self, root, func):
        stack = []
        stack.append(root)
        while stack:
            node = stack.pop()
            if node.Right:
                stack.append(node.Right)
            if node.Left:
                stack.append(node.Left)
            func(node)

    def bfs(self, root, func):
        q = Queue()
        q.put(root)
        while not q.empty():
            node = q.get()
            if node.Left:
                q.put(node.Left)
            if node.Right:
                q.put(node.Right)
            func(node)

    def deleteNode(self, value):
        pass

    def __balanceTree(self):
        pass

    def search(self, value):
        pass

    def prune(self):
        pass

    def graft(self):
        pass