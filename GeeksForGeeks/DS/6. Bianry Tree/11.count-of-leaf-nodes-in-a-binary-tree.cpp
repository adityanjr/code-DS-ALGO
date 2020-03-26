// http://www.geeksforgeeks.org/write-a-c-program-to-get-count-of-leaf-nodes-in-a-binary-tree

#include <iostream>
#include "bt.h"

int getLeafCount(node *root){
	if(root == NULL)
		return 0;
	if(!root->left && !root->right)
		return 1;
	return getLeafCount(root->left) + getLeafCount(root->right);
}

int main(){
	node *root = newNode(1);
  root->left        = newNode(2);
  root->right       = newNode(3);
  root->left->left  = newNode(4);
  root->left->right = newNode(5);    
  
  /*get leaf count of the above created tree*/
  printf("Leaf count of the tree is %d", getLeafCount(root));
	return 0;
}

