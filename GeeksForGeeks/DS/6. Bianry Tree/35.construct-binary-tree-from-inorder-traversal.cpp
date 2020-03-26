// http://www.geeksforgeeks.org/construct-binary-tree-from-inorder-traversal

#include <iostream>
#include <algorithm>
#include "bt.h"

node *buildTree(int *inorder, int start, int end){
	if(start > end)
		return NULL;
	int i = max_element(inorder+start, inorder+start+end-start+1) - (inorder+start);
	i += start;
	node *n = newNode(inorder[i]);
	node *left = buildTree(inorder, start, i-1);
	node *right = buildTree(inorder, i+1, end);
	n->left = left;
	n->right = right;
	return n;
}

int main(){
	/* Assume that inorder traversal of following tree is given
         40
       /   \
      10     30
     /         \
    5          28 */

    int inorder[] = {5, 10, 40, 30, 28};
    int len = sizeof(inorder)/sizeof(inorder[0]);
    struct node *root = buildTree(inorder, 0, len - 1);

    /* Let us test the built tree by printing Insorder traversal */
    printf("\n Inorder traversal of the constructed tree is \n");
    printInorder(root);
	return 0;
}

