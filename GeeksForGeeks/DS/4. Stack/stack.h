// stack header file

#include <iostream>
using namespace std;

struct node {
	int data;
	node *next;
};

void push(node **root, int data){
	node *ptr = new node;
	ptr->data = data;
	ptr->next = *root;
	*root = ptr;
}

int pop(node **root){
	int tmp = (*root)->data;
	node *ptr = *root;
	*root = (*root)->next;
	delete(ptr);
	return tmp;
}

int peek(node *root){
	return root->data;
}

bool isEmpty(node *root){
	if(root == NULL)
		return true;
	return false;
}
