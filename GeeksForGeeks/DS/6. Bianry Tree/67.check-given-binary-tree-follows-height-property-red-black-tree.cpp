// http://www.geeksforgeeks.org/check-given-binary-tree-follows-height-property-red-black-tree

#include <iostream>
#include "bt.h"

bool isBalUtil(node *root, int &min, int &max){
	if(root == NULL)
		return true;
	int lmin=0, lmax=0, rmin=0, rmax=0;
	if(isBalUtil(root->left, lmin, lmax) == false)
		return false;
	if(isBalUtil(root->right, rmin, rmax) == false)
		return false;
	min = (lmin < rmin ? lmin:rmin);
	max = (lmax > rmax ? lmax:rmax);
	if(max <= 2*min)
		return true;
	return false;
}

bool isBalanced(node *root){
	int min=0;
	int max=0;
	isBalUtil(root, min, max);
	if(max <= 2*min){
		return true;
	}
	return false;
}

int main(){
	node * root = newNode(10);
    //root->left = newNode(5);
    root->right = newNode(100);
    root->right->left = newNode(50);
    root->right->right = newNode(150);
    root->right->left->left = newNode(40);
    isBalanced(root)? cout << "Balanced" : cout << "Not Balanced";
	return 0;
}

