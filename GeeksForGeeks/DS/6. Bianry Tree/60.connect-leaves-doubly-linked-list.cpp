// http://www.geeksforgeeks.org/connect-leaves-doubly-linked-list
/**/

#include <iostream>
#include "bt.h"

node *extractLeafList(node *root, node **head){
	if(root == NULL)
		return NULL;
	if(!root->left && !root->right){
		root->right = (*head);
		*head = root;
		return NULL;
	}
	node *r = funct(root->right, head);
	node *l = funct(root->left, head);
	root->left = l;
	root->right = r;
	return root;
}

void printList(node *head){
	while(head){
		cout<<head->data<<" ";
		head = head->right;
	}
}

int main(){
	node *head = NULL;
    node *root = newNode(1);
     root->left = newNode(2);
     root->right = newNode(3);
     root->left->left = newNode(4);
     root->left->right = newNode(5);
     root->right->right = newNode(6);
     root->left->left->left = newNode(7);
     root->left->left->right = newNode(8);
     root->right->right->left = newNode(9);
     root->right->right->right = newNode(10);

     printf("Inorder Trvaersal of given Tree is:\n");
     printInorder(root);

     root = extractLeafList(root, &head);

     printf("\nExtracted Double Linked list is:\n");
     printList(head);

     printf("\nInorder traversal of modified tree is:\n");
     printInorder(root);
	return 0;
}

