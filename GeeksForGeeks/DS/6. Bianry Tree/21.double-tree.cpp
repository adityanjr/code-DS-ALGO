// http://www.geeksforgeeks.org/double-tree/

#include <iostream>
#include <climits>
#include "bt.h"
using namespace std;

void doubleTree(node *root){
    if(root == NULL)
        return;
    node *n = newNode(root->data);
    n->left = root->left;
    root->left = n;
    doubleTree(root->left->left);
    doubleTree(root->right);
}

int main(){
	/* Constructed binary tree is
            1
          /   \
        2      3
      /  \
    4     5
  */
  struct node *root = newNode(1);
  root->left        = newNode(2);
  root->right       = newNode(3);
  root->left->left  = newNode(4);
  root->left->right = newNode(5);
  
  printf("Inorder traversal of the original tree is \n");
  printInorder(root);
 
  doubleTree(root);
   
  printf("\n Inorder traversal of the double tree is \n");  
  printInorder(root);
	return 0;
}