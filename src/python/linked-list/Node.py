#!/usr/bin/python3

"""
Node class

Pythonic implementation of Linked list
"""

__author__ = "Sunil"
__email__ = "suba5417@colorado.edu"

class Node(object):
    __value = None
    __previous = None
    __next = None

    def __init__(self, value, previous=None, nxt=None):
        self.__value = value
        self.__previous = previous
        self.__next = nxt

    @property
    def Value(self):
        return self.__value

    @Value.setter
    def Value(self, value):
        self.__value = value

    @property
    def Previous(self):
        return self.__previous

    @Previous.setter
    def Previous(self, previous):
        self.__previous = previous

    @property
    def Next(self):
        return self.__next

    @Next.setter
    def Next(self, nxt):
        self.__next = nxt