// http://www.geeksforgeeks.org/inorder-tree-traversal-without-recursion-and-without-stack
/**/

#include <iostream>
#include "bt.h"

void MorrisTraversal(node *root){
	if(root == NULL)	
		return;
	node *curr, *pre;
	curr = root;
	while(curr != NULL){
		if(curr->left == NULL){
			cout<<curr->data<<" ";
			curr = curr->right;
		}
		else {
			pre = curr->left;
			while(pre->right && pre->right != curr){
				pre = pre->right;
			}
			if(pre->right == NULL){
				pre->right = curr;
				curr = curr->left;
			}
			else {
				pre->right = NULL;
				cout<<curr->data<<" ";
				curr = curr->right;
			}
		}
	}
}

int main(){
	node *root = newNode(1);
  root->left        = newNode(2);
  root->right       = newNode(3);
  root->left->left  = newNode(4);
  root->left->right = newNode(5); 
 
  MorrisTraversal(root);
	return 0;
}

