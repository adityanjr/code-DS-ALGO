// http://www.geeksforgeeks.org/foldable-binary-trees

#include <iostream>
#include "bt.h"

bool isMirrorImage(node *root1, node *root2){
	if(root1 == NULL && root2 == NULL)
		return true;
	if(root1 == NULL || root2 == NULL)
		return false;
	return isMirrorImage(root1->left, root2->right) && isMirrorImage(root1->right, root2->left);
}

bool isFoldable(node *root){
	if(root == NULL)
		return true;
	return isMirrorImage(root->left, root->right);
}

int main(){
	/* The constructed binary tree is
         1
       /   \
      2     3
      \    /
       4  5
  */
  struct node *root = newNode(1);
  root->left        = newNode(2);
  root->right       = newNode(3);
  root->right->left  = newNode(4);
  root->left->right = newNode(5);
 
  if(isFoldable(root) == 1)
  { printf("\n tree is foldable"); }
  else
  { printf("\n tree is not foldable"); }
	return 0;
}

