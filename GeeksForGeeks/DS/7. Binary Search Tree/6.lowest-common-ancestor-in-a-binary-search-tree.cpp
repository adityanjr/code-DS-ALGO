// http://www.geeksforgeeks.org/lowest-common-ancestor-in-a-binary-search-tree

#include <iostream>
#include <climits>
#include "bst.h"

node *lca(node *root, int k1, int k2){
	if(root == NULL)
		return NULL;
	if(root->data > k1 && root->data  >k2)
		return lca(root->left, k1, k2);
	else if(root->data < k1 && root->data < k2)
		return lca(root->right, k1, k2);
	else {
		return root;
	}
}

int main(){
	// Let us construct the BST shown in the above figure
    node *root        = newNode(20);
    root->left               = newNode(8);
    root->right              = newNode(22);
    root->left->left         = newNode(4);
    root->left->right        = newNode(12);
    root->left->right->left  = newNode(10);
    root->left->right->right = newNode(14);
 
    int n1 = 10, n2 = 14;
    struct node *t = lca(root, n1, n2);
    printf("LCA of %d and %d is %d \n", n1, n2, t->data);
 
    n1 = 14, n2 = 8;
    t = lca(root, n1, n2);
    printf("LCA of %d and %d is %d \n", n1, n2, t->data);
 
    n1 = 10, n2 = 22;
    t = lca(root, n1, n2);
    printf("LCA of %d and %d is %d \n", n1, n2, t->data);
	return 0;
}