// http://www.geeksforgeeks.org/inorder-successor-in-binary-search-tree

#include <iostream>
#include <climits>
#include "bst.h"
using namespace std;

node *inOrderSuccessor(node *root, node *tmp){
	if(root == NULL)
		return NULL;
	if(root->data > tmp->data){
		node *t = inOrderSuccessor(root->left, tmp);
		if(!t || t->data > root->data)
			return root;
		return t;
	}
	else if(root->data <= tmp->data){
		return inOrderSuccessor(root->right, tmp);
	}
	return NULL;
}

int main(){
	node* root = NULL, *temp, *succ;

  //creating the tree given in the above diagram
  root = insert(root, 20);
  root = insert(root, 8);
  root = insert(root, 22);
  root = insert(root, 4);
  root = insert(root, 12);
  root = insert(root, 10);
  root = insert(root, 14);
  temp = root->left->right->right;

  succ =  inOrderSuccessor(root, temp);
  if(succ !=  NULL)
    cout<<"\n Inorder Successor of "<<temp->data<<"is "<<succ->data;
  else
    cout<<"\n Inorder Successor doesn't exit";
	return 0;
}
