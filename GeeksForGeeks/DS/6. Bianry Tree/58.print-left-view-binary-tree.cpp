// http://www.geeksforgeeks.org/print-left-view-binary-tree/

#include <iostream>
#include "bt.h"

void leftView(node *root, int *maxLevel, int level){
	if(root == NULL)
		return;
	if(level > *maxLevel){
		*maxLevel = level;
		cout<<root->data<<" ";
	}
	leftView(root->left, maxLevel, level+1);
	leftView(root->right, maxLevel, level+1);
	
}

int main(){
 node *root = newNode(12);
    root->left = newNode(10);
    root->right = newNode(30);
    root->right->left = newNode(25);
    root->right->right = newNode(40);
    int level = 0;
    leftView(root, &level, 1);
	return 0;
}

