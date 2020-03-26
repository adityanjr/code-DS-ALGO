// http://www.geeksforgeeks.org/print-bst-keys-in-the-given-range

#include <iostream>
#include <cstdio>
#include "bst.h"

void Print(node *root, int k1, int k2){
    if(root == NULL)
        return;
    if(root->data < k1){
        Print(root->right, k1, k2);
        return;
    }
    if(root->data > k2){
        Print(root->left, k1, k2);
        return;
    }
    Print(root->left, k1, k2);
    if(root->data > k1 && root->data < k2)
        cout<<root->data<<" ";
    Print(root->right, k1, k2);
}

int main(){
    node *root = new struct node;
  int k1 = 10, k2 = 25;

  /* Constructing tree given in the above figure */
  root = newNode(20);
  root->left = newNode(8);
  root->right = newNode(22);
  root->left->left = newNode(4);
  root->left->right = newNode(12);

  Print(root, k1, k2);

    return 0;
}
