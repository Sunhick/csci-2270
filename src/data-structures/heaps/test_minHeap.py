#!/usr/bin/python3

"""
minHeaps

Pythonic implementation of Heaps
"""

__author__ = "Sunil"
__email__ = "suba5417@colorado.edu"

import unittest

from minHeap import MinHeap

class test_MinHeap(unittest.TestCase):
    """
    Test heap create, delete, insert
    """

    heap = None

    def __init__(self):
        self.heap = MinHeap()

    def setUp(self):
        pass

    def tearDown(self):
        pass

    def testCase(self):
        pass