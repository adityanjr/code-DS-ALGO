// http://www.geeksforgeeks.org/check-two-nodes-cousins-binary-tree

#include <iostream>
#include "bt.h"

bool isCousin(node *root, node *n, node *m, int level, int *fix){
	if(root == NULL)
		return false;
	if((root->left == n || root->left == m) && (root->right == n || root->right == m))
  		return false;
	else if((root->left == n || root->left == m) || (root->right == n || root->right == m)) {
		if(*fix == -1)
			*fix = level;
		else
			return (*fix == level);
	}
	return isCousin(root->left, n, m, level+1, fix) || isCousin(root->right, n, m, level+1, fix);
	
}

int main(){
	node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->left->right->right = newNode(15);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->left->right = newNode(8);

    node *Node1,*Node2;
    Node1 = root->left->right->right;
    Node2 = root->right->left->right;
	int fix = -1;
    isCousin(root,Node1,Node2, 1, &fix)? puts("Yes"): puts("No");
	return 0;
}

