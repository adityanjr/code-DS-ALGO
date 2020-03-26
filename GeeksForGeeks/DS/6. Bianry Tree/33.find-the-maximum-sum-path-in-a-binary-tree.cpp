// http://www.geeksforgeeks.org/find-the-maximum-sum-path-in-a-binary-tree

#include <iostream>
#include <map>
#include "bt.h"
using namespace std;

void verticalSum(node *root, map<int, int> &M, int key){
	if(root == NULL)
		return;
	M[key] += root->data;
	verticalSum(root->left, M, key-1);
	verticalSum(root->right, M, key+1);
}

void verticalSumMain(node *root){
	if(root == NULL)
		return;
	map<int, int> M;
	verticalSum(root, M, 0);
	map<int, int>::iterator iter;
	for(iter = M.begin(); iter != M.end(); iter++){
		cout<<iter->first<<"-->"<<iter->second<<'\n';
	}
}

int main(){

	/* Create following Binary Tree
              1
            /    \
          2        3
         / \      / \
        4   5    6   7
  
        */
	node *root = newNode(1);
  	root->left = newNode(2);
  	root->right = newNode(3);
  	root->left->left = newNode(4);
  	root->left->right = newNode(5);
  	root->right->left = newNode(6);
  	root->right->right = newNode(7);
 
    verticalSumMain(root);
	return 0;
}