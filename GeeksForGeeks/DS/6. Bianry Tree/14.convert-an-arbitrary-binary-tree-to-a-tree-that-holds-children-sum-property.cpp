// http://www.geeksforgeeks.org/convert-an-arbitrary-binary-tree-to-a-tree-that-holds-children-sum-property/

#include <iostream>
#include "bt.h"

void increment(node *root, int diff){
    int sum = 0;
    if(root->left){
        root->left->data += diff;
        increment(root->left, diff);
    }
    else if(root->right) {
        root->right->data += diff;
        increment(root->right, diff);
    }
}

void convertTree(node *root){
    if(root == NULL || (root->left == NULL && root->right == NULL))
        return;
    funct(root->right);
    funct(root->left);
    int sum = 0;
    if(root->right)
        sum += root->right->data;
    if(root->left)
        sum += root->left->data;
    int diff = sum-root->data;
    if(diff > 0){
        root->data += diff;
    }
    else if(diff < 0){
        increment(root, -diff);
    }
}

int main(){
	node *root = newNode(50);
  root->left        = newNode(7);
  root->right       = newNode(2);
  root->left->left  = newNode(3);
  root->left->right = newNode(5);
  root->right->left  = newNode(1);
  root->right->right = newNode(30);
 
  printf("\n Inorder traversal before conversion ");
  printInorder(root);
 
  convertTree(root);
 
  printf("\n Inorder traversal after conversion ");
  printInorder(root);
	return 0;
}

