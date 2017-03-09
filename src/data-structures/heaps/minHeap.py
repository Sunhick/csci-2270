#!/usr/bin/python3

"""
minHeaps

Pythonic implementation of Heaps
"""

__author__ = "Sunil"
__email__ = "suba5417@colorado.edu"

class MinHeap(object):
    """
    Implementation of min heap(aka priority queue) using array
    """
    container = None

    def __init__(self):
        container = list()

    def AddValue(self, value):
        # Add value at the end and call sift to restore heapy
        # property.
        container.append(value)
        self.__sift()

    def RemoveValue(self, value):
        if not container:
            raise ValueError("Heap is empty")
        # pop value from the root of heap. and call heapifty
        # to restore the min heap property.
        pop = container[0]
        self.__heapify()
        return pop

    def __heapify(self):
        pass

    def __sift(self):
        pass