// http://www.geeksforgeeks.org/remove-nodes-root-leaf-paths-length-k

#include <iostream>
#include "bt.h"

node *removeShortPathNodes(node *root, int level, int k){
	if(root == NULL)
		return NULL;
	root->left = removeShortPathNodes(root->left, level+1, k);
	root->right = removeShortPathNodes(root->right, level+1, k);
	
	if(!root->left && !root->right && k > level){
		delete(root);
		return NULL;
	}
	return root;
}

int main(){
	int k = 4;
    node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->left->left->left = newNode(7);
    root->right->right = newNode(6);
    root->right->right->left = newNode(8);
    cout << "Inorder Traversal of Original tree" << endl;
    printInorder(root);
    cout << endl;
    cout << "Inorder Traversal of Modified tree" << endl;
    node *res = removeShortPathNodes(root, 1, k);
    printInorder(res);
	return 0;
}

