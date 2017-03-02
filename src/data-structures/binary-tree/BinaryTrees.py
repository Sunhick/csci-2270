#!/usr/bin/python3

"""
Node definition

Pythonic implementation of binary trees
"""

from Node import Node

class BinaryTree(object):
    __root = None

    def __init__(self):
        __root = None

    def AddValue(self, value):
        self.AddNode(Node(value))

    def AddNode(self, node):
        self.__addNode(node, self.__root)

    def __addNode(self, node, parent):
        if parent is None:
            parent = node;
            return
        if node.Value > parent.Value:
            # Node has to be added to right
            if parent.Right is None:
                parent.Right = node
                node.Parent = parent
                return
            else:
                self.__addNode(node, parent.Right)
        if node.Value < parent.Value:
            # node goes to the left
            if parent.Left is None:
                parent.Left = node
                node.Parent = parent
                return
            else:
                self.__addNode(node, parent.Left)