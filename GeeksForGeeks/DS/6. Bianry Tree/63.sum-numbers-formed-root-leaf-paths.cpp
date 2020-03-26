// http://www.geeksforgeeks.org/sum-numbers-formed-root-leaf-paths

#include <iostream>
#include "bt.h"

void treePathSumRec(node *root, int *sum, int s){
	if(root == NULL)
		return;
	s *= 10;
	s += root->data;
	if(!root->left && !root->right){
		*sum += s;
		cout<<s<<" ";
		return;
	}
	treePathSumRec(root->left, sum, s);
	treePathSumRec(root->right, sum, s);
}

int treePathsSum(node *root){
	int sum = 0;
	treePathSumRec(root, &sum, 0);
	return sum;
}

int main(){
	node *root = newNode(6);
    root->left        = newNode(3);
    root->right       = newNode(5);
    root->right->right= newNode(7);
    root->left->left  = newNode(2);
    root->left->right = newNode(5);
    root->right->right = newNode(4);
    root->left->right->left = newNode(7);
    root->left->right->right = newNode(4);
    printf("Sum of all paths is %d", treePathsSum(root));
	return 0;
}

