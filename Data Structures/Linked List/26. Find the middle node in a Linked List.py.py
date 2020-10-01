# -*- coding: utf-8 -*-
"""
Created on Thu Oct  1 15:58:09 2020

@author: 91891
"""

#Creating a single node class
class Node:
    #A single node object will contain two fields: Data and Next Pointer
    def __init__(self,data):
        self.data=data
        self.next=None
    #Method to get data
    def getData(self):
        return self.data
    #Method to get next pointer
    def getNext(self):
        return self.next
    #Method to set next pointer
    def setNext(self,Next):
        self.next=Next
##Creating a singly linked list class       
class SinglyLinkedList:
    #each list object must contain a head
    def __init__(self,head):
        self.head=Node(head)
    #appends a new node with specified data to the end of the list
    #Time Complexity:O(n) as it iterates through all thhe previous nodes
    def append(self,item):
        current=self.head
        #while we don't reach the last node, keep on going to the next node
        while current.next!=None:
            current=current.next
        current.next=Node(item)
    #displays the current LinkedList
    def display(self):
        res=[self.head.data]
        current=self.head
        #while we don't reach the last node, keep on going to the next node and add that node's data to a list to display
        while current.next!=None:
            res.append(current.next.data)
            current=current.next
        return res

# An efficient way to get the middle node in one scan
# Time Complexity: O(n)
"""How it works:
    Use two pointers. One moves at double the speed of the other hence when the 
    fast pointer reaches the end, slow pointer reaches the middle.
    In case the linkedList's length(n) is even, it returns node at index n/2""" 
    
def findMiddleNode(singlyLinkedList):
    #initializing both pointers to point to the head node
    fastPtr=singlyLinkedList.head
    slowPtr=singlyLinkedList.head
    while(fastPtr!=None):
        fastPtr=fastPtr.next
        if(fastPtr==None):
            #returns node at slow pointer if fast pointer reaches the end
            return slowPtr.data
        fastPtr=fastPtr.next
        slowPtr=slowPtr.next
    #If the linkedList has even number of nodes, it will return node at index n/2 where n is the length of the linkedList
    return slowPtr.data

def driverFunction():
    s1=SinglyLinkedList(1)
    numberOfNode=int(input("How many nodes do you want? "))
    for i in range(2,numberOfNode+1):
        s1.append(i)
    print("The middle node of the list "+str(s1.display())+" is:")
    print(findMiddleNode(s1))
driverFunction()