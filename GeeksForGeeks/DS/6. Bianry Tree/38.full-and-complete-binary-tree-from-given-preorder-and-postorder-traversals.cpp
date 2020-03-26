// http://www.geeksforgeeks.org/full-and-complete-binary-tree-from-given-preorder-and-postorder-traversals

#include <iostream>
#include <algorithm>
#include "bt.h"

node *constructTree(int *pre, int *post, int start, int end, int *preStart){
	if(end-start+1 <1 )
		return NULL;
	node *n = newNode(pre[*preStart]);
	n->left = NULL;
	n->right = NULL;
	++*preStart;
	if(end-start+1 >1){
		int i = find(post+start, post+end+1, pre[*preStart+1]) - post;
		if(i <= end){
			n->left = constructTree(pre, post, start, i, preStart);
			n->right = constructTree(pre, post, i+1, end, preStart);
		}
	}
	return n;
	
}

int main(){
	int pre[] = {1, 2, 4, 8, 9, 5, 3, 6, 7};
    int post[] = {8, 9, 4, 5, 2, 6, 7, 3, 1};
    int size = sizeof( pre ) / sizeof(int);
	int preStart = 0;
    struct node *root = constructTree(pre, post, 0, size-1, &preStart);

    printf("Inorder traversal of the constructed tree: \n");
    printInorder(root);
	return 0;
}

