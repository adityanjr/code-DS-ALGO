// http://www.geeksforgeeks.org/print-ancestors-of-a-given-binary-tree-node-without-recursion/

#include <iostream>
#include <stack>
#include "bt.h"

void printAncestors(node *root, int key){
	if(root == NULL)
		return;
	stack<node*> s;
	//s.push(root);
	while(1){
		while(root && root->data != key){
			s.push(root);
			root = root->left;
		}
		if(root && root->data == key)
			break;
		if(!s.empty() && s.top()->right == NULL){
			root = s.top();	s.pop();
			while(!s.empty() && s.top()->right == root){
				root = s.top();	s.pop();
			}
		}
		root = (s.empty() ? NULL: s.top()->right);				
	}
	while(!s.empty()){
		cout<<s.top()->data<<" ";
		s.pop();
	}
}

int main(){
	node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->left->left->left = newNode(8);
    root->left->right->right = newNode(9);
    root->right->right->left = newNode(10);
 
    printf("Following are all keys and their ancestors\n");
    for (int key = 1; key <= 10; key++)
    {
        printf("%d: ", key);
        printAncestors(root, key);
        printf("\n");
    }
}
