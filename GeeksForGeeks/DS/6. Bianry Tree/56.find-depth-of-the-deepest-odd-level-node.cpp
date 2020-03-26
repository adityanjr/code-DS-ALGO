// http://www.geeksforgeeks.org/find-depth-of-the-deepest-odd-level-node

#include <iostream>
#include "bt.h"

int depthOfOddLeaf(node *root){
	if(root == NULL)
		return 0;
	if(root->left == NULL && root->right == NULL)
		return 1;
	int Max=0;
	if(root->left){
		if(root->left->left)
			Max = max(Max, 2+depthOfOddLeaf(root->left->left));
		if(root->left->right)
			Max = max(Max, 2+depthOfOddLeaf(root->left->right));
	}
	if(root->right){
		if(root->right->left)
			Max = max(Max, 2+depthOfOddLeaf(root->right->left));
		if(root->right->right)
			Max = max(Max, 2+depthOfOddLeaf(root->right->right));
	}
	return Max;
}

int main(){
	node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->right->left = newNode(5);
    root->right->right = newNode(6);
    root->right->left->right = newNode(7);
    root->right->right->right = newNode(8);
    root->right->left->right->left = newNode(9);
    root->right->right->right->right = newNode(10);
    root->right->right->right->right->left = newNode(11);

    printf("%d is the required depth\n", depthOfOddLeaf(root));
	return 0;
}

