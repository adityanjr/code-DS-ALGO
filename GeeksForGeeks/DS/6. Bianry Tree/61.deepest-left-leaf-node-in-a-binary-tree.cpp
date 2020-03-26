// http://www.geeksforgeeks.org/deepest-left-leaf-node-in-a-binary-tree

#include <iostream>
#include "bt.h"

void deepestLL(node *root, node **res, int *maxLevel, int level){
	if(root == NULL)
		return;
	if(*maxLevel <= level){
		node *tmp = root->left;
		if(tmp && !tmp->left && !tmp->right){
			*res = tmp;
			*maxLevel = level+1;
		}
	}
	deepestLL(root->left, res, maxLevel, level+1);
	deepestLL(root->right, res, maxLevel, level+1);
}

node *deepestLeftLeaf(node *root){
	if(root == NULL)
		return NULL;
	node *res = NULL;
	int maxLevel = 1;
	deepestLL(root, &res, &maxLevel, 1);
	return res;
}

int main(){
	node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->right->left = newNode(5);
    root->right->right = newNode(6);
    root->right->left->right = newNode(7);
    root->right->right->right = newNode(8);
    root->right->left->right->left = newNode(9);
    root->right->right->right->right = newNode(10);

    node *result = deepestLeftLeaf(root);
    if (result)
        cout<<"The deepest left child is " << result->data;
    else
        cout<<"There is no left leaf in the given tree";
	return 0;
}

