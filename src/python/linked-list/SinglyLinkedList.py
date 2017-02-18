#!/usr/bin/python3

"""
Linked list

Pythonic implementation of Linked list
"""

__author__ = "Sunil"
__email__ = "suba5417@colorado.edu"

from LinkedList import LinkedList
from Node import Node

class SinglyLinkedList(LinkedList):
    __head = None
    __count = 0

    def __init__(self):
        pass

    @property
    def Head(self):
        return self.__head

    @property
    def Count(self):
        return self.__count

    def insertNodeAtHead(self, value):
        if not self.__head:
            self.__head = Node(value)
            self.__count += 1
            return
        
        # add node at head
        self.__count += 1
        temp = Node(value)
        temp.Next = self.__head
        self.__head = temp

    def insertNodeAtTail(self, value):
        if not self.__head:
            return self.insertNodeAtHead(value)

        # traverse linked list
        temp = self.__head
        while(not temp.Next):
            temp = temp.Next
        self.__count += 1
        temp.Next = Node(value)

    def insertNodeAt(self, index, value):
        if index > self.__count:
            raise "Index out of range."

        if not self.__head:
            return self.insertNodeAtHead(value)

        temp = self.__head
        position = 0
        while(not temp.Next and index != position):
            temp = temp.Next
            position += 1

        if position <= self.__count:
            self.__count += 1
            temp.Next = Node(value)

    def deleteNode(self, value):
        pass

    def contains(self, value):
        pass