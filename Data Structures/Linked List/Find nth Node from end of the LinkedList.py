# -*- coding: utf-8 -*-
"""
Created on Fri Oct  2 18:01:42 2020

@author: InfamousBolt
"""
"""A python program to find the nth node from end in a Singly LinkedList"""

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
# An efficient approach to get the nth node from end in one scan
# Time Complexity: O(n)
"""How it works:
    We use two pointers: pNthNode and pTemp. Initially, both point to the head of the list.
    pNthNode starts moving only after pTemp has made n moves. From there, both move untill
    pTemp reaches the end. As a result, pNthNode points to the nth node from the end of the list"""
#Note: The following code assumes that the 0th node from end is the last node.    
def nthNodeFromEnd(singlylinkedlist,n):
    if n<0:
        return None
    #count n units from self.head
    temp=singlylinkedlist.head
    count=0
    while count<n and temp!=None:
        temp=temp.next
        count+=1
    #if linked list does not contain n elements return none
    if count<n or temp==None:
        return None
    #keeping tab on the nth element,slide temp untill it reaches end
    #increament nthPointer in the process
    nth=singlylinkedlist.head
    while temp.next!=None:
        temp=temp.next
        nth=nth.next
    #return the data of nth node from end
    return nth.data

#driver function
def driver():
    s1=SinglyLinkedList(1)
    numberOfNode=int(input("How many nodes do you want to be created in the list? "))
    for i in range(2,numberOfNode+1):
        s1.append(i)
    print("We are going to find the nth node from the end of the list...")
    n=int(input("Enter the value of n: "))
    print("The "+str(n)+" node from the end of the list "+str(s1.display())+" is:")
    print(nthNodeFromEnd(s1,n))
driver()
