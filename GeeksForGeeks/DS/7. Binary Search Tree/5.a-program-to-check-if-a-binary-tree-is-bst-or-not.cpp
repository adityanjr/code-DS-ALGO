//http://www.geeksforgeeks.org/a-program-to-check-if-a-binary-tree-is-bst-or-not

#include <iostream>
#include "bst.h"

bool isBST(node *root, int Min, int Max){
	if(root == NULL)
		return true;
    if(root->data < Min || root->data > Max)
	   return false;
    return isBST(root->left, Min, root->data) && isBST(root->right, root->data, Max);
}

bool isBst(node *root, int Min){
	 
}

int main(){
	node *root = newNode(3);
  root->left        = newNode(2);
  root->right       = newNode(5);
  root->left->left  = newNode(1);
  root->left->right = newNode(4); 
 
  if(isBST(root, INT_MIN, INT_MAX))
    printf("Is BST");
  else
    printf("Not a BST");
     
  getchar();
  return 0;
}
