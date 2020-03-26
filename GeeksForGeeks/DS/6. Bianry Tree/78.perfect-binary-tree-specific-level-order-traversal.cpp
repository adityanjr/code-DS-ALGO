// http://www.geeksforgeeks.org/perfect-binary-tree-specific-level-order-traversal

#include <iostream>
#include <queue>
#include "bt.h"

void printSpecificLevelOrder(node *root){
	if(root == NULL)
		return;
	queue<node*> q;
	q.push(root);
	if(root->left){
		q.push(root->left);
		if(root->right)
			q.push(root->right);
	}
	cout<<q.front()->data<<" ";
	q.pop();
	while(!q.empty()){
		node *tmp1 = q.front(); q.pop();
		node *tmp2 = q.front(); q.pop();
		cout<<tmp1->data<<" "<<tmp2->data<<" ";
		if(tmp1->left)
			q.push(tmp1->left);
		if(tmp2->right)
			q.push(tmp2->right);
		if(tmp1->right)
			q.push(tmp1->right);
		if(tmp2->left)
			q.push(tmp2->left);
	}
}

int main(){
	node *root = newNode(1);

    root->left        = newNode(2);
    root->right       = newNode(3);

    root->left->left  = newNode(4);
    root->left->right = newNode(5);
    root->right->left  = newNode(6);
    root->right->right = newNode(7);

    root->left->left->left  = newNode(8);
    root->left->left->right  = newNode(9);
    root->left->right->left  = newNode(10);
    root->left->right->right  = newNode(11);
    root->right->left->left  = newNode(12);
    root->right->left->right  = newNode(13);
    root->right->right->left  = newNode(14);
    root->right->right->right  = newNode(15);

    root->left->left->left->left  = newNode(16);
    root->left->left->left->right  = newNode(17);
    root->left->left->right->left  = newNode(18);
    root->left->left->right->right  = newNode(19);
    root->left->right->left->left  = newNode(20);
    root->left->right->left->right  = newNode(21);
    root->left->right->right->left  = newNode(22);
    root->left->right->right->right  = newNode(23);
    root->right->left->left->left  = newNode(24);
    root->right->left->left->right  = newNode(25);
    root->right->left->right->left  = newNode(26);
    root->right->left->right->right  = newNode(27);
    root->right->right->left->left  = newNode(28);
    root->right->right->left->right  = newNode(29);
    root->right->right->right->left  = newNode(30);
    root->right->right->right->right  = newNode(31);

    cout << "Specific Level Order traversal of binary tree is \n";
    printSpecificLevelOrder(root);
	return 0;
}

