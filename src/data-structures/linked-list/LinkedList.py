#!/usr/bin/python3

"""
Linked list

Pythonic implementation of Linked list
"""

__author__ = "Sunil"
__email__ = "suba5417@colorado.edu"

from abc import ABCMeta, abstractmethod

class LinkedList(object):
    __metaclass__ = ABCMeta

    @abstractmethod
    def insertNodeAtHead(self, value):
        pass

    @abstractmethod
    def insertNodeAtTail(self, value):
        pass

    @abstractmethod
    def insertNodeAt(self, index, value):
        pass

    @abstractmethod
    def deleteNode(self, value):
        pass

    @abstractmethod
    def contains(self, value):
        pass