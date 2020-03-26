// http://www.geeksforgeeks.org/linked-complete-binary-tree-its-creation

#include <iostream>
#include <queue>
#include "bt.h"

void insert(node **root, int data, queue<node*> &q){
	if(*root == NULL){
		*root = newNode(data);
		q.push(*root);
		return;
	}
	node *tmp = q.front();
	if(tmp->left == NULL || !tmp->right == NULL){
		node *n = newNode(data);
		if(!tmp->left){
			tmp->left = n;
		}
		else{
			tmp->right = n;
		}
		q.push(n);
	}
	else {
		q.pop();
		insert(root, data, q);
	}
}

void levelOrder(node *root){
	if(root == NULL)
		return;
	queue<node*> q;
	q.push(root);
	while(!q.empty()){
		node *tmp = q.front();  q.pop();
		cout<<tmp->data<<" ";
		if(tmp->left)
			q.push(tmp->left);
		if(tmp->right)
			q.push(tmp->right);
	}
}

int main(){
	node* root = NULL;
    queue<node*> q;
    int i;

    for(i = 1; i <= 10; ++i)
        insert(&root, i, q);
    levelOrder(root);
	return 0;
}

