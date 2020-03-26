// http://www.geeksforgeeks.org/level-order-traversal-in-spiral-form

#include <iostream>
#include <stack>
#include "bt.h"

void printSpiralRec(node *root, int level, int l2r){
	if(root == NULL)
		return;
	if(level == 1){
		cout<<root->data<<" ";
		return;
	}
	if(l2r){
		printSpiralRec(root->left, level-1, l2r);
		printSpiralRec(root->right, level-1, l2r);
	}
	else {
		printSpiralRec(root->right, level-1, l2r);		
		printSpiralRec(root->left, level-1, l2r);
	}
}

void printSpiral(node *root){
	if(root == NULL)
		return;
	int height = maxDepth(root);
	bool flag = false;
	for(int i=1; i<=height; i++){
		printSpiralRec(root, i, flag);
		flag = !flag;
		cout<<'\n';
	}
}

void printSpiralIter(node *root){
	if(root == NULL)
		return;
	 stack<node*> s1;
	 stack<node*> s2;
	 s1.push(root);
	 while(!s1.empty() || !s2.empty()){
	 	while(!s1.empty()){
	 		node *tmp = s1.top();	s1.pop();
		 	cout<<tmp->data<<" ";
		 	if(tmp->right)
		 		s2.push(tmp->right);
		 	if(tmp->left)
		 		s2.push(tmp->left);
		 }
		 while(!s2.empty()){
	 		node *tmp = s2.top();	s2.pop();
		 	cout<<tmp->data<<" ";
		 	if(tmp->left)
		 		s1.push(tmp->left);
		 	if(tmp->right)
		 		s1.push(tmp->right);
		 }
	 }
}

int main(){
	node *root = newNode(1);
    root->left        = newNode(2);
    root->right       = newNode(3);
    root->left->left  = newNode(7);
    root->left->right = newNode(6);
    root->right->left  = newNode(5);
    root->right->right = newNode(4);
    cout << "Spiral Order traversal of binary tree is \n";
    printSpiralIter(root);
	return 0;
}

