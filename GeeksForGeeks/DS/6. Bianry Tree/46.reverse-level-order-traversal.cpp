// http://www.geeksforgeeks.org/reverse-level-order-traversal

#include <iostream>
#include <stack>
#include <queue>
#include "bt.h"

void reverseLevelOrder(node *root){
	if(root == NULL)
		return;
	stack<node*> s;
	queue<node*> q;
	q.push(root);
	while(!q.empty()){
		node *tmp = q.front();  q.pop();
		if(tmp->right)
			q.push(tmp->right);
		if(tmp->left)
			q.push(tmp->left);
		s.push(tmp);
	}
	while(!s.empty()){
		cout<<s.top()->data<<" ";
		s.pop();
	}
}

void reverseLevel(node *root, int level){
	if(root == NULL)
		return;
	if(level == 1){
		cout<<root->data<<" ";
		return;
	}
	reverseLevel(root->left, level-1);
	reverseLevel(root->right, level-1);
}

void reverseLevelRec(node *root){
	if(root == NULL);
	int h = maxDepth(root);
	for(int i=h; i>=1; i--){
		reverseLevel(root, i);
	}
}

int main(){
	node *root = newNode(1);
    root->left        = newNode(2);
    root->right       = newNode(3);
    root->left->left  = newNode(4);
    root->left->right = newNode(5);

    printf("Level Order traversal of binary tree is \n");
    //reverseLevelOrder(root);
    reverseLevelRec(root);
	return 0;
}

