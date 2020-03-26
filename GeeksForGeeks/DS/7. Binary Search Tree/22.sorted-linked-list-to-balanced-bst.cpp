// http://www.geeksforgeeks.org/sorted-linked-list-to-balanced-bst/

#include <bits/stdc++.h>
using namespace std;

struct node {
    int data;
    node *right, *left;
    node(int d){
        data = d;
        right = left = NULL;
    }
};

node *newNode(int d){
    return new node(d);
}

void preOrder(node* node){
    if (node == NULL)
        return;
    printf("%d ", node->data);
    preOrder(node->left);
    preOrder(node->right);
}

void printList(node *node){
    while(node!=NULL){
        printf("%d ", node->data);
        node = node->right;
    }
}

void push(struct node** head_ref, int new_data) {
    node* new_node = newNode(new_data);
    new_node->right = (*head_ref);
    (*head_ref)    = new_node;
}

int count(node *node){
    int c = 0;
    while(node!=NULL){
        c++;
        node = node->right;
    }
    return c;
}

node *constructUtil(node **head, int n){
    if(n == 0){
        return NULL;
    }
    node *root = newNode(0);
    root->left = constructUtil(head, n/2);
    root->data = (*head)->data;
    (*head) = (*head)->right;
    root->right = constructUtil(head, n - n/2 - 1);
    return root;
}

node *sortedListToBST(node *head){
    int n = count(head);
    return constructUtil(&head, n);
}

int main() {
    node* head = NULL;

    /* Let us create a sorted linked list to test the functions
     Created linked list will be 1->2->3->4->5->6->7 */
    push(&head, 7);
    push(&head, 6);
    push(&head, 5);
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);

    printf("\n Given Linked List ");
    printList(head);

    /* Convert List to BST */
    node *root = sortedListToBST(head);
    printf("\n PreOrder Traversal of constructed BST ");
    preOrder(root);
	return 0;
}
