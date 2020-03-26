// http://www.geeksforgeeks.org/memory-efficient-doubly-linked-list

#include <iostream>
#include <cstdio>
using namespace std;

struct node {
    int data;
    node *diff;
};

node nextNode(node pNode, node pPrevNode){
    return ((node)((int)(pNode->diff)^(int)pPrevNode));
}

void addNode(node **head, int data){
    node *p = new node;
    p->data = data;
    p->diff = NULL;
    if(*head == NULL){
        *head = p;
        return;
    }
    if((*head)->diff == 0){
        (*head)->diff = p;
        p->diff = *head;
        return;
    }
    node *prev = *head;
    node *ptr = (*head)->diff;
    while(ptr->diff - prev){

    }
//    node *rr = ptr->diff - prev;
  //  p->diff = ptr;
}

int main(){
    node* head = NULL;
    addNode(&head, 1);
    addNode(&head, 2);
    cout<<(head - head->diff->diff);
    return 0;
}
