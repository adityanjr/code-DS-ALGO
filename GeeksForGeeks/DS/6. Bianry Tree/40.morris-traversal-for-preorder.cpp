// http://www.geeksforgeeks.org/morris-traversal-for-preorder
/**/


#include <iostream>
#include "bt.h"

node *rightMost(node *root){
	if(root == NULL)
		return NULL;
	while(root->right){
		root = root->right;
	}
	return root;
}

void morrisTraversalPreorder(node *root){
	if(root == NULL)
		return;
	while(root){
		if(root->left == NULL){
			cout<<root->data<<" ";
			root = root->right;
		}
		else {
			node *curr = root->left;
			while(curr->right && curr->right != root)
				curr = curr->right;
			if(curr->right == root){
				curr->right = NULL;
				root = root->right;
			}
			else {
				cout<<root->data<<" ";
				curr->right = root;
				root = root->left;
			}
		}
	}
}

int main(){
	node* root = NULL;

    root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);

    root->left->left = newNode(4);
    root->left->right = newNode(5);

    root->right->left = newNode(6);
    root->right->right = newNode(7);

    root->left->left->left = newNode(8);
    root->left->left->right = newNode(9);

    root->left->right->left = newNode(10);
    root->left->right->right = newNode(11);

    morrisTraversalPreorder(root);

    printf("\n");
    //printPreorder(root);
	return 0;
}

