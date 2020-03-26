// http://www.geeksforgeeks.org/write-a-c-program-to-calculate-size-of-a-tree/

#include <iostream>
#include "bt.h"

int size(node *root){
	if(root == NULL)
		return 0;
	return size(root->left) + 1 + size(root->right);
}

int main(){
	struct node *root = newNode(1);
  root->left        = newNode(2);
  root->right       = newNode(3);
  root->left->left  = newNode(4);
  root->left->right = newNode(5); 
  root->left->right->left = newNode(6);
 
  printf("Size of the tree is %d", size(root)); 
	return 0;
}

