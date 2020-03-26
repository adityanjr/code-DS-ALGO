// http://www.geeksforgeeks.org/iterative-postorder-traversal-using-stack

#include <iostream>
#include <stack>
#include "bt.h"

void postOrderIterative(node *root){
	if(root == NULL){
		return;
	}
	stack<node*> s;

	do {
		while(root){
			if(root->right)
				s.push(root->right);
			s.push(root);
			root = root->left;
		}
		root = s.top(); s.pop();
		if(root->right && !s.empty() && s.top() == root->right){
			s.pop();
			s.push(root);
			root = root->right;
		}
		else {
			cout<<root->data<<" ";
			root = NULL;
		}
	}
	while(!s.empty());
}

int main(){
	node* root = NULL;
    root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    postOrderIterative(root);
	return 0;
}

