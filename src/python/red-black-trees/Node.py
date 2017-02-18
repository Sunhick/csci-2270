#!/usr/bin/python3

"""
Node definition

Pythonic implementation of red black trees
"""

from enum import Enum

class Color(Enum):
    Red = 1
    Black = 0
    Invalid = 10

class Node(object):
    __left = __right = __color = __value = None
    def __init__(self, value, left=None, right=None, color=Color.Invalid):
        self.__left = left
        self.__right = right
        self.__color = color
        self.__value = value

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

    def FlipColor(self):
        if self.__color == Color.Red:
            self.__color = Color.Black
        
        if self.__color == Color.Black:
            self.__color = Color.Red
