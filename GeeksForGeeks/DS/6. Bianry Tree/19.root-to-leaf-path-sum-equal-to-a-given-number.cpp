// http://www.geeksforgeeks.org/root-to-leaf-path-sum-equal-to-a-given-number

#include <iostream>
#include "bt.h"

bool hasPathSum(node *root, int sum){
	if(root == NULL || sum<0)
		return false;
	if(root->left == NULL && root->right == NULL && sum == root->data)
		return true;
	return hasPathSum(root->left, sum-root->data) || hasPathSum(root->right, sum-root->data);
}

int main(){
	node *root = newNode(10);
  root->left        = newNode(8);
  root->right       = newNode(2);
  root->left->left  = newNode(3);
  root->left->right = newNode(5);
  root->right->left = newNode(2);
 
  if(hasPathSum(root, 21))
    printf("There is a root-to-leaf path with sum %d", 21);
  else
    printf("There is no root-to-leaf path with sum %d", 21);
	return 0;
}

