#!/usr/bin/python3

"""
Node definition

Pythonic implementation of red black trees
"""

from enum import Enum
from functools import partial

class Color(Enum):
    Red = 1
    Black = 0
    Invalid = 10

class Node(object):
    __left = None
    __right = None
    __color = None
    __value = None
    __parent = None

    def __init__(self, value, left=None, right=None, parent=None, color=Color.Invalid):
        self.__left = left
        self.__right = right
        self.__color = color
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
    def Color(self):
        return self.__color

    @Color.setter
    def Color(self, color):
        self.__color = color

    @property
    def Value(self):
        return self.__value

    @Value.setter
    def Value(self, left):
        self.__value = value

    @property
    def Parent(self):
        return self.__parent

    def FlipColor(self):
        if self.__color == Color.Red:
            self.__color = Color.Black
        
        if self.__color == Color.Black:
            self.__color = Color.Red

# Vanilla nodes
RedNode = partial(Node, color=Color.Red)
BlackNode = partial(Node, color=Color.Black)
