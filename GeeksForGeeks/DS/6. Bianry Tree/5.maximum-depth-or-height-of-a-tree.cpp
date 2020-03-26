// http://www.geeksforgeeks.org/write-a-c-program-to-find-the-maximum-depth-or-height-of-a-tree/

#include <iostream>
#include "bt.h"

int Depth(node *root){
	if(root == NULL)
		return 0;
	return 1+ max(Depth(root->left), Depth(root->right));
}

int main(){
	struct node *root = newNode(1);
 
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5); 
    root->left->right->right = newNode(6);
   
    printf("Hight of tree is %d", Depth(root));
	return 0;
}

