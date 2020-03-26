// http://www.geeksforgeeks.org/floor-and-ceil-from-a-bst

#include <iostream>
#include "bst.h"

int Ceil(node *root, int key){
	if(root == NULL)
		return INT_MAX;
	if(root->data == key)
		return root->data;
	if(root->data > key)
		return min(root->data, Ceil(root->left, key));
	else
		return Ceil(root->right, key);
}

int main(){
	node *root = newNode(8);

    root->left = newNode(4);
    root->right = newNode(12);

    root->left->left = newNode(2);
    root->left->right = newNode(6);

    root->right->left = newNode(10);
    root->right->right = newNode(14);

    for(int i = 0; i < 16; i++)
        printf("%d  %d\n", i, Ceil(root, i));

	return 0;
}

