// http://www.geeksforgeeks.org/binary-tree-to-binary-search-tree-conversion

#include <iostream>
#include <vector>
#include <algorithm>
#include "bst.h"

void binaryTreeToVector(node *root, vector<int> &v){
	if(root == NULL)
		return;
	binaryTreeToVector(root->left, v);
	v.push_back(root->data);
	binaryTreeToVector(root->right, v);
}

void VectorToBinary(node *root, vector<int> &v){
	if(root == NULL)
		return;
	VectorToBinary(root->right, v);
	root->data = v[v.size()-1];
	v.pop_back();
	VectorToBinary(root->left, v);
}

void binaryTreeToBST(node *&root){
	if(root == NULL)
		return;
	vector<int> v;
	binaryTreeToVector(root, v);
	sort(v.begin(), v.end());
	VectorToBinary(root, v);
}

int main(){
	node *root = NULL;
 
    /* Constructing tree given in the above figure
          10
         /  \
        30   15
       /      \
      20       5   */
    root = newNode(10);
    root->left = newNode(30);
    root->right = newNode(15);
    root->left->left = newNode(20);
    root->right->right = newNode(5);
 
    // convert Binary Tree to BST
    binaryTreeToBST (root);
 
    cout<<"Following is Inorder Traversal of the converted BST: \n";
    printInorder (root);
}
