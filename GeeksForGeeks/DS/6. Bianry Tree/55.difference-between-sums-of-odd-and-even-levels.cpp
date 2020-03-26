// http://www.geeksforgeeks.org/difference-between-sums-of-odd-and-even-levels

#include <iostream>
#include <queue>
#include "bt.h"

void getLevelDiff(node *root, int *diff, int level){
	if(root == NULL)
		return;
	if(level%2)
		*diff += root->data;
	else
		*diff -= root->data;
	getLevelDiff(root->left, diff, level+1);
	getLevelDiff(root->right, diff, level+1);
}

int getLevelDiffIter(node *root){
	if(root == NULL)
		return 0;
	int diff = 0;
	queue<node*> q;
	q.push(root);
	int level = 1;
	while(!q.empty()){
		int count = q.size();
		while(count){
			node *tmp = q.front();  q.pop();
			if(level%2){
				diff += tmp->data;
			}
			else {
				diff -= tmp->data;
			}
			if(tmp->left)
				q.push(tmp->left);
			if(tmp->right)
				q.push(tmp->right);
			count--;
		}
		level++;
	}
	return diff;
}

int main(){
	node *root = newNode(5);
    root->left = newNode(2);
    root->right = newNode(6);
    root->left->left  = newNode(1);
    root->left->right = newNode(4);
    root->left->right->left = newNode(3);
    root->right->right = newNode(8);
    root->right->right->right = newNode(9);
    root->right->right->left = newNode(7);
    int diff = 0;
    getLevelDiff(root, &diff, 1);
    printf("%d is the required difference\n", diff);
    cout<<getLevelDiffIter(root);
	return 0;
}

