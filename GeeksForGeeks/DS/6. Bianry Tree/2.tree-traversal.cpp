// http://www.geeksforgeeks.org/618/

#include <iostream>
#include "bt.h"

void preorder(node *root){
	if(root == NULL)
		return;
	cout<<root->data<<" ";
	printPreorder(root->left);
	printPreorder(root->right);
}

void inorder(node *root){
	if(root == NULL)
		return;
	inorder(root->left);
	cout<<root->data;
	inorder(root->right);
}

void postorder(node *root){
	if(root == NULL)
		return;
	postorder(root->left);
	postorder(root->right);
	cout<<root->data;
}

int main(){
	 struct node *root  = newNode(1);
     root->left         = newNode(2);
     root->right        = newNode(3);
     root->left->left   = newNode(4);
     root->left->right  = newNode(5); 
 
     printf("\n Preorder traversal of binary tree is \n");
     preorder(root);
 
     printf("\n Inorder traversal of binary tree is \n");
     inorder(root);  
 
     printf("\n Postorder traversal of binary tree is \n");
     postorder(root);
	 return 0;
}

