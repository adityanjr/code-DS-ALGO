// http://www.geeksforgeeks.org/print-ancestors-of-a-given-node-in-binary-tree

#include <iostream>
#include "bt.h"

bool printAncestors(node *root, int d){
	if(root == NULL)
		return false;
	if(root->data == d)
		return true;
	if(printAncestors(root->left, d) || printAncestors(root->right, d)){
		cout<<root->data<<" ";
		return true;
	}
	else
		return false;
}

int main(){
	/* Construct the following binary tree
              1
            /   \
          2      3
        /  \
      4     5
     /
    7
  */
  struct node *root = newNode(1);
  root->left        = newNode(2);
  root->right       = newNode(3);
  root->left->left  = newNode(4);
  root->left->right = newNode(5);
  root->left->left->left  = newNode(7);

  printAncestors(root, 7);
	return 0;
}

