// http://www.geeksforgeeks.org/print-nodes-top-view-binary-tree

#include <iostream>
#include <queue>
#include "bt.h"

void printTopView(node *root){
	if(root == NULL)
		return;
	int left = 1;
	int right = -1;
	queue<node*> q;
	queue<int> side;
	q.push(root);
	side.push(0);
	while(!q.empty()){
		node *tmp = q.front();  q.pop();
		int level = side.front();   side.pop();
		if(level > right || level < left){
			if(level > right)
				right = level;
			if(level < left)
				left = level;
			cout<<tmp->data<<" ";
		}
		if(tmp->left){
			q.push(tmp->left);
			side.push(level-1);
		}
		if(tmp->right){
			q.push(tmp->right);
			side.push(level+1);
		}
	}
}

int main(){
	/* Create following Binary Tree
             1
           /  \
          2    3
           \
            4
             \
              5
               \
                6*/
        node *root = newNode(1);
        root->left = newNode(2);
        root->right = newNode(3);
        root->left->right = newNode(4);
        root->left->right->right = newNode(5);
        root->left->right->right->right = newNode(6);
        root->right->left = newNode(7);
        root->right->left->left = newNode(8);
        root->right->left->left->left = newNode(9);
        printTopView(root);
	return 0;
}

