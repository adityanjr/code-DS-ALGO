// http://www.geeksforgeeks.org/convert-a-given-tree-to-sum-tree

#include <iostream>
#include "bt.h"

void toSumTree(node *root){
	if(root == NULL)
		return;
	int sum = 0;
	if(root->left)
		sum += root->left->data;
	if(root->right)
		sum += root->right->data;
	root->data = sum;

	toSumTree(root->left);
	toSumTree(root->right);
	sum = 0;
	if(root->left)
		sum += root->left->data;
	if(root->right)
		sum += root->right->data;
	root->data += sum;
}

int main(){
	node *root = NULL;
  	int x;

  /* Constructing tree given in the above figure */
  root = newNode(10);
  root->left = newNode(-2);
  root->right = newNode(6);
  root->left->left = newNode(8);
  root->left->right = newNode(-4);
  root->right->left = newNode(7);
  root->right->right = newNode(5);

  toSumTree(root);

  // Print inorder traversal of the converted tree to test result of toSumTree()
  printf("Inorder Traversal of the resultant tree is: \n");
  printInorder(root);
	return 0;
}

