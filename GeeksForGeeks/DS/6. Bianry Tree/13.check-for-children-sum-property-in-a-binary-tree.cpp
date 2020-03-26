// http://www.geeksforgeeks.org/check-for-children-sum-property-in-a-binary-tree

#include <iostream>
#include "bt.h"

bool isSumProperty(node *root){
	if(root == NULL || (root->left == NULL && root->right == NULL))
		return true;
	int sum = 0;
	if(root->left)
		sum += root->left->data;
	if(root->right)
		sum += root->right->data;
	if(sum == root->data)
		return isSumProperty(root->left) && isSumProperty(root->right);
	return false;
}

int main(){
	struct node *root  = newNode(10);
  root->left         = newNode(8);
  root->right        = newNode(2);
  root->left->left   = newNode(3);
  root->left->right  = newNode(5);
  root->right->right = newNode(2);
  root->right->right->left = newNode(2);
  if(isSumProperty(root))
    printf("The given tree satisfies the children sum property ");
  else
    printf("The given tree does not satisfy the children sum property ");
	return 0;
}

