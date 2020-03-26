// http://www.geeksforgeeks.org/largest-independent-set-problem/

#include <bits/stdc++.h>
using namespace std;

struct node {
	int data;
	int liss;
	node *left, *right;
};

node *newNode(int data){
	node *n = new node;
	n->data = data;
	n->left = n->right = NULL;
	n->liss = 0;
	return n;
}

int LISS(node *root){
	if(root == NULL)
		return 0;
	if(root->liss)
		return root->liss;
	if(root->left ==NULL && root->right == NULL)
		return (root->liss = 1);
	//excl root;
	int excl = LISS(root->left) + LISS(root->right);
	
	//incl root
	int inc = 1;
	if(root->left)
		inc += LISS(root->left->left) + LISS(root->left->right);
	if(root->right)
		inc += LISS(root->right->left) + LISS(root->right->right);

	root->liss = max(inc, excl);
	return root->liss;
}

int main(){
	// Let us construct the tree given in the above diagram
	// HEAP
    struct node *root         = newNode(20);
    root->left                = newNode(8);
    root->left->left          = newNode(4);
    root->left->right         = newNode(12);
    root->left->right->left   = newNode(10);
    root->left->right->right  = newNode(14);
    root->right               = newNode(22);
    root->right->right        = newNode(25);

    printf ("Size of the Largest Independent Set is %d ", LISS(root));
	return 0;
}

