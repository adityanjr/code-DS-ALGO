// http://www.geeksforgeeks.org/boundary-traversal-of-binary-tree

#include <iostream>
#include <queue>
#include "bt.h"

// Method 1
void printLeftWall(node *root){
	if(root == NULL)
		return;
	cout<<root->data<<" ";
	printLeftWall(root->left);
}

void printLeafNode(node *root, bool left, bool right){
	if(root == NULL)
		return;
	if(!root->left && !root->right && !left && !right)
		cout<<root->data<<" ";
	printLeafNode(root->left, left, false);
	printLeafNode(root->right, false, right);
}

void printRightWall(node *root){
	if(root == NULL)
		return;
	printRightWall(root->right);
	cout<<root->data<<" ";
}
void printBoundary(node *root){
	if(root == NULL)
		return;
	printLeftWall(root);
	printLeafNode(root, true, true);
	printRightWall(root);
}

//Method 2 -> more correct for below kinda tree
/*
                1
               /  \
              2    3
               \   /\
               6  5  4
        	    \   \
                10   11
*/
void fillLeftV(node *root, node **leftV, int level){
	if(root == NULL)
		return;
	if(leftV[level] == NULL){
		leftV[level] = root;
	}
	fillLeftV(root->left, leftV, level+1);
	fillLeftV(root->right, leftV, level+1);
}

void fillRightV(node *root, node **rightV, int level){
	if(root == NULL)
		return;
	if(rightV[level] == NULL){
		rightV[level] = root;
	}
	fillRightV(root->right, rightV, level+1);
	fillRightV(root->left, rightV, level+1);
}

void printLeaf(node *root, node **leftV, node **rightV, int level){
	if(root == NULL)
		return;
	if(!root->left && !root->right){
		if(leftV[level] != root && rightV[level] != root){
			cout<<root->data<<" ";
		}
	}
	else {
		printLeaf(root->left, leftV, rightV, level+1);
		printLeaf(root->right, leftV, rightV, level+1);
	}
}

void printBoundary1(node *root){
	int h = height(root);
	node* leftV[h];
	node* rightV[h];
	for(int i=0; i<h; i++){
		leftV[i] = rightV[i] = NULL;
	}
	fillLeftV(root, leftV, 0);
	fillRightV(root, rightV, 0);

	// Print left
	for(int i=0; i<h; i++){
		if(leftV[i]){
			cout<<leftV[i]->data<<" ";
		}
	}
	
	//Print Leaf
	printLeaf(root, leftV, rightV, 0);
	
	//Print Right
	for(int i=h-1; i>=0; i--){
		if(rightV[i] && leftV[i] != rightV[i]){
			cout<<rightV[i]->data<<" ";
		}
	}
}

int main(){
	// Let us construct the tree given in the above diagram
    struct node *root         = newNode(20);
    root->left                = newNode(8);
    root->left->left          = newNode(4);
    root->left->right         = newNode(12);
    root->left->right->left   = newNode(10);
    root->left->right->right  = newNode(14);
    root->right               = newNode(22);
    root->right->right        = newNode(25);

    printBoundary( root );
	return 0;
}

