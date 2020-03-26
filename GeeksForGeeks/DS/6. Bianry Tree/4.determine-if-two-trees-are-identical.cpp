// http://www.geeksforgeeks.org/write-c-code-to-determine-if-two-trees-are-identical

#include <iostream>
#include "bt.h"

bool identicalTrees(node *root1, node *root2){
	if(root1 == NULL && root2 == NULL)
		return true;
	if(root1 == NULL || root2 == NULL)
		return false;
	if(root1->data == root2->data)
		return identicalTrees(root1->left, root2->left) && identicalTrees(root1->right, root2->right);
	return false;
}

int main(){
	node *root1 = newNode(1);
    node *root2 = newNode(1);
    root1->left = newNode(2);
    root1->right = newNode(3);
    root1->left->left  = newNode(4);
    root1->left->right = newNode(5); 
 
    root2->left = newNode(2);
    root2->right = newNode(3);
    root2->left->left = newNode(4);
    root2->left->right = newNode(5); 
 
    if(identicalTrees(root1, root2))
        printf("Both tree are identical.");
    else
        printf("Trees are not identical.");
	return 0;
}

