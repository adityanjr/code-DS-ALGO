// http://www.geeksforgeeks.org/check-leaves-level

#include <iostream>
#include "bt.h"

bool checkRec(node *root, int level, int maxHeight){
	if(root == NULL)
		return true;
	if(root->left == NULL && root->right == NULL)
		return (level == maxHeight);
	return checkRec(root->left, level+1, maxHeight) && checkRec(root->right, level+1, maxHeight);
}

bool check(node *root){
	node *ptr = root;
	int level = 1;
	while(ptr->left){
		level++;
		ptr = ptr->left;
	}
	return checkRec(root, 1, level);
}

int main(){
	node *root = newNode(12);
    root->left = newNode(5);
    root->left->left = newNode(3);
    root->left->right = newNode(9);
    root->left->left->left = newNode(1);
    root->left->right->left = newNode(1);
    if (check(root))
        printf("Leaves are at same level\n");
    else
        printf("Leaves are not at same level\n");
	return 0;
}

