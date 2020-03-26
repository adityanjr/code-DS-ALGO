// http://www.geeksforgeeks.org/given-a-binary-tree-how-do-you-remove-all-the-half-nodes

#include <iostream>
#include "bt.h"

node *removeHalfNodes(node **root){
	if(*root == NULL)
		return NULL;
	if(!(*root)->left && !(*root)->right)
		return *root;

	node *l = NULL;
	node *r = NULL;
	l = removeHalfNodes(&(*root)->left);
	r = removeHalfNodes(&(*root)->right);
	if(l && r){
		(*root)->left = l;
		(*root)->right = r;
		return *root;
	}
	*root = NULL;
	node *tmp = *root;
	if(l == NULL)
		*root = r;
	else
		*root = l;
	delete(tmp);
	return *root;
}

int main(){
	node *NewRoot=NULL;
    struct node *root = newNode(2);
    root->left        = newNode(7);
    root->right       = newNode(5);
    root->left->right = newNode(6);
    root->left->right->left=newNode(1);
    root->left->right->right=newNode(11);
    root->right->right=newNode(9);
    root->right->right->left=newNode(4);

    printf("Inorder traversal of given tree \n");
    printInorder(root);

    NewRoot = removeHalfNodes(&root);

    printf("\nInorder traversal of the modified tree \n");
    printInorder(NewRoot);
	return 0;
}

