// http://www.geeksforgeeks.org/given-a-binary-tree-print-out-all-of-its-root-to-leaf-paths-one-per-line

#include <iostream>
#include "bt.h"

void printPathRec(node *root, int *arr, int level){
	if(root == NULL){
		return;
	}
	arr[level] = root->data;
	if(root->left == NULL && root->right == NULL){
		printArray(arr, level+1);
		return;
	}
	else {
		printPathRec(root->left, arr, level+1);
		printPathRec(root->right, arr, level+1);
	}
}

void printPaths(node *root){
	int arr[100];
	int level = 0;
	printPathRec(root, arr, level);
}

int main(){
	node *root = newNode(1);
  	root->left        = newNode(2);
  	root->right       = newNode(3);
 	root->left->left  = newNode(4);
  	root->left->right = newNode(5); 
 
  	/* Print all root-to-leaf paths of the input tree */
  	printPaths(root);
	return 0;
}

