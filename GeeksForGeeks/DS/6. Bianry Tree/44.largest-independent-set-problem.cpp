// http://www.geeksforgeeks.org/largest-independent-set-problem

#include <iostream>
#include "bt.h"

int LISS(node *root){
	if(root == NULL)
		return 0;
	int child = LISS(root->left) + LISS(root->right);
	int grandchild = 1;
	if(root->left){
		grandchild += LISS(root->left->left) + LISS(root->left->right);
	}
	if(root->right){
		grandchild += LISS(root->right->left) + LISS(root->right->right);
	}
	return max(child, grandchild);
}

int main(){
	node *root         = newNode(20);
    root->left                = newNode(8);
    root->left->left          = newNode(4);
    root->left->right         = newNode(12);
    root->left->right->left   = newNode(10);
    root->left->right->right  = newNode(14);
    root->right               = newNode(22);
    root->right->right        = newNode(25);

    printf ("Size of the Largest Independent Set is %d ", LISS(root));
	return 0;
}

