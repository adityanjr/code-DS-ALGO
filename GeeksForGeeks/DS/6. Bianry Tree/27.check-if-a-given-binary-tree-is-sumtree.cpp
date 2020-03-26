// http://www.geeksforgeeks.org/check-if-a-given-binary-tree-is-sumtree

#include <iostream>
#include "bt.h"

bool isLeafNode(node *root){
	if(root && !root->left && !root->right)
		return true;
	return false;
}

bool isSumTree(node *root){
	if(root == NULL || isLeafNode(root))
		return true;
	int sum = 0;
	if(root->left){
		if(isLeafNode(root->left)){
			sum += root->left->data;
		}
		else
			sum += 2*root->left->data;
	}
	if(root->right){
		if(isLeafNode(root->right)){
			sum += root->right->data;
		}
		else
			sum += 2*root->right->data;
	}
	if(sum == root->data)
		return isSumTree(root->left) && isSumTree(root->right);
	return false;
}

int main(){
	node *root  = newNode(26);
    root->left         = newNode(10);
    root->right        = newNode(3);
    root->left->left   = newNode(4);
    root->left->right  = newNode(6);
    root->right->right = newNode(3);
    if(isSumTree(root))
        printf("The given tree is a SumTree ");
    else
        printf("The given tree is not a SumTree ");

	return 0;
}

