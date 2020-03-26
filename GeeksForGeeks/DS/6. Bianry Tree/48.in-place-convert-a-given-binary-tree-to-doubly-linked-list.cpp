// http://www.geeksforgeeks.org/in-place-convert-a-given-binary-tree-to-doubly-linked-list/

#include <iostream>
#include "bt.h"

void printList(node *head){
	while(head){
		cout<<head->data<<" ";
		head = head->right;
	}
}

node *getRightMost(node *root){
	if(root == NULL)
		return NULL;
	while(root->right){
		root = root->right;
	}
	return root;
}

node *bintree2list(node *root){
	if(root == NULL)
		return NULL;
	node *left = bintree2list(root->left);
	node *right = bintree2list(root->right);
	node *rightMost = getRightMost(left);
	if(rightMost){
		rightMost->right = root;
	}
	root->left = rightMost;
	if(right)
		right->left = root;
	root->right = right;
	if(left)
		return left;
	else
		return root;
}

// small
node *bintree2list1(node *root){
	if(root == NULL)
		return NULL;
	node *ptr = root->left;
	node *head = root;
	if(ptr){
		while(ptr->right){
			ptr = ptr->right;
		}
		head = funct(root->left);
		ptr->right = root;
		root->left = root;
	}
	root->right = funct(root->right);
	return head;
}

int main(){
	node *root        = newNode(10);
    root->left        = newNode(12);
    root->right       = newNode(15);
    root->left->left  = newNode(25);
    root->left->right = newNode(30);
    root->right->left = newNode(36);

    // Convert to DLL
    node *head = bintree2list(root);

    // Print the converted list
    printList(head);
	return 0;
}

