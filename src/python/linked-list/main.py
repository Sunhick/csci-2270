#!/usr/bin/python3

"""
Linked list test file

Pythonic implementation of Linked list
"""

__author__ = "Sunil"
__email__ = "suba5417@colorado.edu"

from SinglyLinkedList import SinglyLinkedList

def main():
    linkedlist = SinglyLinkedList()
    linkedlist.insertNodeAtHead(5)
    linkedlist.insertNodeAtHead(15)
    linkedlist.insertNodeAtHead(115)
    linkedlist.insertNodeAtHead(1115)

    print("count = ", linkedlist.Count)
    node = linkedlist.Head
    while(node):
        print(node.Value)
        node = node.Next

if __name__ == '__main__':
    main()