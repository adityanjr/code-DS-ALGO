// http://www.geeksforgeeks.org/the-great-tree-list-recursion-problem

#include <iostream>
#include "bt.h"

node *getLeftMost(node *root){
	node *ptr = root;
	while(ptr->left){
		ptr = ptr->left;
	}
	return ptr;
}

node *getRightMost(node *root){
	node *ptr = root;
	while(ptr->right){
		ptr = ptr->right;
	}
	return ptr;
}

node *treeToDListRec(node *root, bool left){
	if(root == NULL)
		return NULL;
	node *l = treeToDListRec(root->left, false);
	node *r = treeToDListRec(root->right, true);
	if(l){
		l->right = root;
		root->left = l;
	}
	if(r){
		r->left = root;
		root->right = r;
	}
	if(left)
		return getLeftMost(root);
	return getRightMost(root);
}

node *treeToDList(node *root){
	if(root == NULL)
		return NULL;
	return treeToDListRec(root, true);
}

int main(){
	node *root = newNode(1);
  	root->left        = newNode(2);
  	root->right       = newNode(3);
  	root->left->left  = newNode(4);
  	root->left->right = newNode(5); 
  	node *head = treeToDList(root);
  	node *ptr =head;
  	while(ptr){
  		cout<<ptr->data<<" ";
  		ptr = ptr->right;
	  }
	return 0;
}

