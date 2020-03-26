// http://www.geeksforgeeks.org/convert-binary-tree-threaded-binary-tree

#include <bits/stdc++.h>
using namespace std;

struct node {
	int data;
	node *right, *left;
	bool isThread;
};

node *newNode(int data){
	node *n = new node;
	n->data = data;
	n->isThread = 0;
	n->right = NULL;
	n->left = NULL;
	return n;
}

void bar(node *root){
	if(root == NULL)
		return;
	while(root){
		if(root->left == NULL){
			root = root->right;
		}
		else {
			node *ptr = root->left;
			while(ptr->right && ptr->right != root){
				ptr = ptr->right;
			}
			if(ptr->right == NULL){
				ptr->right = root;
				ptr->isThread = 1;
				root = root->left;
			}
			else{
				root = root->right;
			}
		}
	}
}

void ThreadInorder(node *root){
	if(root == NULL)
		return;
	while(root->left)
		root = root->left;
	while(root){
		cout<<root->data<<" ";
		if(root->isThread)
			root = root->right;
		else {
			root = root->right;
			while(root && root->left)
				root = root->left;
		}
	}
}

int main(){
	/*       1
            / \
           2   3
          / \ / \
         4  5 6  7   */
    node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->left->right = newNode(10);
    root->right->right = newNode(7);

    bar(root);

    cout << "Inorder traversal of creeated threaded tree is\n";
    ThreadInorder(root);

}
