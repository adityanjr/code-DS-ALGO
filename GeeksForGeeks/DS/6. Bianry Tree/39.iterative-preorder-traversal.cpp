// http://www.geeksforgeeks.org/iterative-preorder-traversal

#include <iostream>
#include <stack>
#include "bt.h"

void iterativePreorder(node *root){
	if(root == NULL)
		return;
	stack<node*> s;
	s.push(root);
	while(!s.empty()){
		node *tmp = s.top();
		cout<<tmp->data<<" ";
		s.pop();
		if(tmp->right){
			s.push(tmp->right);
		}
		if(tmp->left){
			s.push(tmp->left);
		}
 	}
}

//Just pushing right nodes to stack
void iterativePreorder1(node *root){
	if(root == NULL)
		return;
	stack<node*> s;
	while(root){
		while(root){
			if(root->right){
				s.push(root->right);
			}
			cout<<root->data<<" ";
			root = root->left;
		}
		if(!s.empty()){
			root=s.top();   s.pop();
		}
	}
}

int main(){
	/* Constructed binary tree is
            10
          /   \
        8      2
      /  \    /
    3     5  2
  */
  struct node *root = newNode(10);
  root->left        = newNode(8);
  root->right       = newNode(2);
  root->left->left  = newNode(3);
  root->left->right = newNode(5);
  root->right->left = newNode(2);
  iterativePreorder(root);
	return 0;
}
