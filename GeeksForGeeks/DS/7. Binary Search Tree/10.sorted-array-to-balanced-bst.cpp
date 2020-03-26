// http://www.geeksforgeeks.org/sorted-array-to-balanced-bst

#include <iostream>
#include "bst.h"

node *sortedArrayToBST(int *arr, int start, int end){
	if(start>end)
  	    return NULL;
	int i = (start+end)/2;
	node *root = newNode(arr[i]);
	root->left = sortedArrayToBST(arr, start, i-1);
	root->right = sortedArrayToBST(arr, i+1, end);
	return root;
}

int main(){
	int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr)/sizeof(arr[0]);
 
    /* Convert List to BST */
    node *root = sortedArrayToBST(arr, 0, n-1);
    printf("\n PreOrder Traversal of constructed BST ");
    printInorder(root);
    getchar();
}
