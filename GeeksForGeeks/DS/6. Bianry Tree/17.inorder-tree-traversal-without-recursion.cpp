// http://www.geeksforgeeks.org/inorder-tree-traversal-without-recursion

#include <iostream>
#include <stack>
#include "bt.h"

void inOrder(node *root){
	stack<node*> s;
	bool done = false;
	node *ptr = root;
	while(!done){
		if(ptr){
			s.push(ptr);
			ptr = ptr->left;
		}
		else {
			if(!s.empty()){
				ptr = s.top();	s.pop();
				cout<<ptr->data<<" ";
				ptr = ptr->right;
			}
			else {
				done = 1;
			}
		}
		
	}
}

void inorder(node *root){
	if(root == NULL)
		return;
	stack<node*> s;
	node *ptr = root;
	while(!s.empty() || ptr){
		while(ptr){
			s.push_back(ptr);
			ptr = ptr->left;
		}
		ptr = s.back(); s.pop();
		cout<<ptr->data<<" ";
		ptr = ptr->right;
	}
}

int main(){
	/* Constructed binary tree is
            1
          /   \
        2      3
      /  \
    4     5
  */
  node *root = newNode(1);
  root->left        = newNode(2);
  root->right       = newNode(3);
  root->left->left  = newNode(4);
  root->left->right = newNode(5); 
 
  inOrder(root);
	return 0;
}

