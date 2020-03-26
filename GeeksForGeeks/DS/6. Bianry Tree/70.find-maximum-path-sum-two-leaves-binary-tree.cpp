// http://www.geeksforgeeks.org/find-maximum-path-sum-two-leaves-binary-tree
/**/

#include <iostream>
#include "bt.h"

int maxPathSum(node *root, int *res){
	if(root == NULL)
		return 0;
	if(!root->left && !root->right){
		if(*res < root->data){
			cout<<root->data<<" ";
			*res = root->data;
		}
		return root->data;
	}
	int l = maxPathSum(root->left, res);
	int r = maxPathSum(root->right, res);
	if(l+r+root->data > *res)
		*res = l+r+root->data;
	return max(r, l)+root->data;
}

int main(){
	node *root = newNode(-15);
    root->left = newNode(5);
    root->right = newNode(6);
    root->left->left = newNode(-8);
    root->left->right = newNode(1);
    root->left->left->left = newNode(2);
    root->left->left->right = newNode(6);
    root->right->left = newNode(3);
    root->right->right = newNode(9);
    root->right->right->right= newNode(0);
    root->right->right->right->left= newNode(4);
    root->right->right->right->right= newNode(-1);
    root->right->right->right->right->left= newNode(10);
    int res = INT_MIN;
    maxPathSum(root, &res);
    cout << "Max pathSum of the given binary tree is " << res;
	return 0;
}

