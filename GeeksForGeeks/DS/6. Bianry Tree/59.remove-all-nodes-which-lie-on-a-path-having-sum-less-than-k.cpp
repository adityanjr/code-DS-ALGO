// http://www.geeksforgeeks.org/remove-all-nodes-which-lie-on-a-path-having-sum-less-than-k

#include <iostream>
#include "bt.h"

node* pruneRec(node **root, int k, int *sum){
	if(*root == NULL)
		return NULL;
		
	int lsum = *sum + (*root)->data;
	int rsum = lsum;
	node *l = pruneRec(&(*root)->left, k, &lsum);
	node *r = pruneRec(&(*root)->right, k, &rsum);
	*sum = max(rsum, lsum);

	if(*sum < k){
		*root = NULL;
		delete(*root);
	}
	return *root;
}

node *prune(node *root, int k){
	int sum = 0;
	return pruneRec(&root, k, &sum);
}

int main(){
	int k = 45;
    struct node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->left->left->left = newNode(8);
    root->left->left->right = newNode(9);
    root->left->right->left = newNode(12);
    root->right->right->left = newNode(10);
    root->right->right->left->right = newNode(11);
    root->left->left->right->left = newNode(13);
    root->left->left->right->right = newNode(14);
    root->left->left->right->right->left = newNode(15);

    printf("Tree before truncation\n");
    printInorder(root);

    root = prune(root, k); // k is 45

    printf("\n\nTree after truncation\n");
    printInorder(root);
	return 0;
}

