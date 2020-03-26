// http://www.geeksforgeeks.org/find-the-minimum-element-in-a-binary-search-tree/

#include <iostream>
#include "bst.h"

int minValue(node *root){
	if(root == NULL)
		return -1;
	while(root->left){
	    root = root->left;
	}
	return root->data;
}

int main(){
	node* root = NULL;
  root = insert(root, 4);
  insert(root, 2);
  insert(root, 1);
  insert(root, 3);
  insert(root, 6);
  insert(root, 5);  
 
  printf("\n Minimum value in BST is %d", minValue(root));
  getchar();
}
