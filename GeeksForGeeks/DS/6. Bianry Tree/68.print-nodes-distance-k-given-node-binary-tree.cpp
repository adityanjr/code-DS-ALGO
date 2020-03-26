// http://www.geeksforgeeks.org/print-nodes-distance-k-given-node-binary-tree

#include <iostream>
#include "bt.h"

void printkdistanceDown(node *root, int k){
	if(root == NULL)
		return;
	if(k == 0){
		cout<<root->data<<" ";
		return;
	}
	printkdistanceDown(root->left, k-1);
	printkdistanceDown(root->right, k-1);
}

int printkdistanceNode(node *root, node *target, int k){
	if(root == NULL)
		return -1;
	if(root == target){
		printkdistanceDown(root, k);
		return 0;
	}
	int dl = printkdistanceNode(root->left, target, k);
	if(dl != -1){
		if(dl+1 == k){
			cout<<root->data<<" ";
		}
		else {
			printkdistanceDown(root->right, k-dl-2);
		}
		return dl+1;
	}
	
	int dr = printkdistanceNode(root->right, target, k);
	if(dr != -1){
		if(dr+1 == k){
			cout<<root->data<<" ";
		}
		else {
			printkdistanceDown(root->left, k-dr-2);
		}
		return dr+1;
	}
	return -1;
}

int main(){
	node * root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->left->right->left = newNode(6);
    root->left->right->right = newNode(7);
    node * target = root->left->right;
    printkdistanceNode(root, target, 2);
	return 0;
}

