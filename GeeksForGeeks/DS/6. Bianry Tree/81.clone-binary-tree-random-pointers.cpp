// http://www.geeksforgeeks.org/clone-binary-tree-random-pointers

#include <iostream>
using namespace std;

struct node {
    int data;
    node *right, *left, *random;
};

void printInorder(node *root){
	 if(root == NULL)
	     return;
	 printInorder(root->left);
	 cout<<root->data<<" ";
	 printInorder(root->right);
}

node *newNode(int data){
	 node *n = new node;
	 n->data = data;
	 n->right = n->left = n->random = NULL;
}

void doubleTree(node *root){
    if(root == NULL)
        return;
    node *n = newNode(root->data);
    n->left = root->left;
    root->left = n;
    doubleTree(root->left->left);
    doubleTree(root->right);
}

void setRandom(node *root){
	if(root == NULL)
	    return;
	if(root->random)
	    root->left->random = root->random->left;
	else
	    root->left->random = NULL;
	setRandom(root->left->left);
	setRandom(root->right);
}

void seperate(node *root, node **clone){
    if(root == NULL)
	    return;
    *clone = root->left;
	root->left = root->left->left;
	seperate(root->left, &(*clone)->left);
	seperate(root->right, &(*clone)->right);
}

node *cloneTree(node *root){
	 if(root == NULL)
	     return NULL;
	 doubleTree(root);
	 setRandom(root);
	 node *clone = NULL;
	 seperate(root, &clone);
	 return clone;
}

int main(){
	//Test No 1
    node *tree = newNode(1);
    tree->left = newNode(2);
    tree->right = newNode(3);
    tree->left->left = newNode(4);
    tree->left->right = newNode(5);
    tree->random = tree->left->right;
    tree->left->left->random = tree;
    tree->left->right->random = tree->right;
 /*
//  Test No 2
//  Node *tree = NULL;
/*
//  Test No 3
    Node *tree = newNode(1);
 
//  Test No 4
    Node *tree = newNode(1);
    tree->left = newNode(2);
    tree->right = newNode(3);
    tree->random = tree->right;
    tree->left->random = tree;
 
  Test No 5
    Node *tree = newNode(1);
    tree->left = newNode(2);
    tree->right = newNode(3);
    tree->left->left = newNode(4);
    tree->left->right = newNode(5);
    tree->right->left = newNode(6);
    tree->right->right = newNode(7);
    tree->random = tree->left;
*/
//  Test No 6
  /*  Node *tree = newNode(10);
    Node *n2 = newNode(6);
    Node *n3 = newNode(12);
    Node *n4 = newNode(5);
    Node *n5 = newNode(8);
    Node *n6 = newNode(11);
    Node *n7 = newNode(13);
    Node *n8 = newNode(7);
    Node *n9 = newNode(9);
    tree->left = n2;
    tree->right = n3;
    tree->random = n2;
    n2->left = n4;
    n2->right = n5;
    n2->random = n8;
    n3->left = n6;
    n3->right = n7;
    n3->random = n5;
    n4->random = n9;
    n5->left = n8;
    n5->right = n9;
    n5->random = tree;
    n6->random = n9;
    n9->random = n8;
 
/*  Test No 7
    Node *tree = newNode(1);
    tree->left = newNode(2);
    tree->right = newNode(3);
    tree->left->random = tree;
    tree->right->random = tree->left;
*/
    cout << "Inorder traversal of original binary tree is: \n";
    printInorder(tree);
 
    node *clone = cloneTree(tree);
 
    cout << "\n\nInorder traversal of cloned binary tree is: \n";
    printInorder(clone);
    getchar();
}
