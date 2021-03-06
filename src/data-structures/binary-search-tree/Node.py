#!/usr/bin/python3

"""
Node definition

Pythonic implementation of binary trees
"""

__author__ = "Sunil"
__email__ = "suba5417@colorado.edu"

class Node(object):
    __left = None
    __right = None
    __value = None
    __parent = None

    def __init__(self, value, left=None, right=None, parent=None):
        self.__left = left
        self.__right = right
        self.__value = value
        self.__parent = parent

    @property
    def Left(self):
        return self.__left

    @Left.setter
    def Left(self, left):
        self.__left = left

    @property
    def Right(self):
        return self.__right

    @Right.setter
    def Right(self, right):
        self.__right = right

    @property
    def Value(self):
        return self.__value

    @Value.setter
    def Value(self, value):
        self.__value = value

    @property
    def Parent(self):
        return self.__parent

    @Parent.setter
    def Parent(self, parent):
        self.__parent = parent
