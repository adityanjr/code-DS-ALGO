/*
 *
 *  This problem was asked by Google.

    Given two singly linked lists that intersect at some point, find the intersecting node. The lists are non-cyclical.

    For example, given A = 3 -> 7 -> 8 -> 10 and B = 99 -> 1 -> 8 -> 10, return the node with value 8.

    In this example, assume nodes with the same value are the exact same node objects.

    Do this in O(M + N) time (where M and N are the lengths of the lists) and constant space.
 *
 *
 *
 *
 */ 
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;
};
int length(struct Node *head) {
    int len = 0;
    while(head != NULL) {
        len++;
        head = head->next;
    }
    return len;
}
struct Node* findMergePoint(struct Node *A, struct Node *B) {
    int m = length(A);
    int n = length(B);
    int d = n - m;
    if(m > n) {
        struct Node* temp = A;
        A = B;
        B = temp;
        d = m - n;
    }
    int i;
    for(i=0;i<d;i++) {
        B = B->next;
    }
    while(A != NULL && B != NULL) {
        if(A == B) {
            return A;
        }
        A = A->next;
        B = B->next;
    }
    return NULL;
}
int main()
{
    struct Node *head1 = NULL, *head2 = NULL;
    struct Node *temp[7];
    for(int i=0;i<7;i++) {
        temp[i] = (Node *)malloc(sizeof(Node));
    }
    temp[0]->data = 4;
    temp[0]->next = temp[1];
    temp[1]->data = 6;
    temp[1]->next = temp[2];
    temp[2]->data = 7;
    temp[2]->next = temp[3];
    temp[3]->data = 1;
    temp[3]->next = NULL;
    temp[4]->data = 9;
    temp[4]->next = temp[5];
    temp[5]->data = 3;
    temp[5]->next = temp[6];
    temp[6]->data = 5;
    temp[6]->next = temp[2];

    head1 = temp[0];
    head2 = temp[4];
    struct Node *C = findMergePoint(head1, head2); 
    cout<<C->data;
    return 0;
}
