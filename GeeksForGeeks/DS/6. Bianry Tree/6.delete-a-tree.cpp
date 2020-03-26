// http://www.geeksforgeeks.org/write-a-c-program-to-delete-a-tree

#include <iostream>
#include "bt.h"

void deleteTree(node *root){
	if(root == NULL)
		return;
	deleteTree(root->left);
	deleteTree(root->right);
	delete(root);
}

int main(){
	node *root = newNode(1); 
    root->left            = newNode(2);
    root->right          = newNode(3);
    root->left->left     = newNode(4);
    root->left->right   = newNode(5); 
   
    deleteTree(root); 
    root = NULL;
 
    printf("\n Tree deleted ");
	return 0;
}

