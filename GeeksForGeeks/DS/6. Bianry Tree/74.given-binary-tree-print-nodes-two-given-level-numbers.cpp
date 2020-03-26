// http://www.geeksforgeeks.org/given-binary-tree-print-nodes-two-given-level-numbers

#include <iostream>
#include <queue>
#include "bt.h"

void printLevels(node *root, int low, int high){
	if(root == NULL)
		return;
	queue<node*> q;
	q.push(root);
	int level = 1;
	while(!q.empty() && level <= high){
		int count = q.size();
		while(count){
			node *tmp = q.front();  q.pop();
			if(level >= low)
				cout<<tmp->data<<" ";
			if(tmp->left)
				q.push(tmp->left);
			if(tmp->right)
				q.push(tmp->right);
			count--;
		}
		cout<<'\n';
		level++;
	}
}

int main(){
	node *root        = newNode(20);
    root->left               = newNode(8);
    root->right              = newNode(22);
    root->left->left         = newNode(4);
    root->left->right        = newNode(12);
    root->left->right->left  = newNode(10);
    root->left->right->right = newNode(14);

    cout << "Level Order traversal between given two levels is";
    printLevels(root, 2, 3);
	return 0;
}

