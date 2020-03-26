// http://www.geeksforgeeks.org/level-order-tree-traversal

#include <iostream>
#include <queue>
#include "bt.h"

// O(n2)
void printLevelOrderRec(node *root, int level){
	if(root == NULL)
		return;
	if(level == 1){
		cout<<root->data<<" ";
		return;
	}
	printLevelOrderRec(root->left, level-1);
	printLevelOrderRec(root->right, level-1);
}

void printLevelOrder(node *root){
	if(root == NULL)
		return;
	int height = maxDepth(root);
	for(int i=1; i<=height; i++){
		printLevelOrderRec(root, i);
		cout<<'\n';
	}
}

void printLevelOrderIter(node *root){
	queue<node*> q;
	q.push(root);
	q.push(NULL);
	bool flag = false;
	while(!q.empty()){
		node *tmp = q.front();	q.pop();
		if(tmp == NULL){
			if(flag)
				return;
			q.push(NULL);
			cout<<'\n';
			flag = true;
			continue;
		}
		flag = false;
		cout<<tmp->data<<" ";
		if(tmp->left)
			q.push(tmp->left);
		if(tmp->right)
			q.push(tmp->right);
	}
}

int main(){
	node *root = newNode(1);
  	root->left        = newNode(2);
  	root->right       = newNode(3);
  	root->left->left  = newNode(4);
  	root->left->right = newNode(5);
 
  	printf("Level Order traversal of binary tree is \n");
  	//printLevelOrder(root);
  	printLevelOrderIter(root);
	return 0;
}

