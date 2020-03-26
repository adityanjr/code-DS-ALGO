// http://www.geeksforgeeks.org/write-an-efficient-c-function-to-convert-a-tree-into-its-mirror-tree

#include <iostream>
#include "bt.h"

void mirror(node *root){
	if(root == NULL)
		return;
	mirror(root->left);
	mirror(root->right);
	node *tmp = root->left;
	root->left = root->right;
	root->right = tmp;
}

int main(){
	node *root = newNode(1);
  root->left        = newNode(2);
  root->right       = newNode(3);
  root->left->left  = newNode(4);
  root->left->right = newNode(5); 
   
  /* Print inorder traversal of the input tree */
  printf("\n Inorder traversal of the constructed tree is \n");
  printInorder(root);
   
  /* Convert tree to its mirror */
  mirror(root); 
   
  /* Print inorder traversal of the mirror tree */
  printf("\n Inorder traversal of the mirror tree is \n");  
  printInorder(root);
   
	return 0;
}

