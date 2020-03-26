// http://www.geeksforgeeks.org/iterative-method-to-find-height-of-binary-tree

#include <iostream>
#include <queue>
#include "bt.h"

int treeHeight(node *root){
	if(root == NULL)
		return 0;
	queue<node*> q;
	q.push(root);
	int height = 0;
	while(1){
		int count = q.size();
		if(count == 0){
			return height;
		}
		height++;
		while(count > 0){
			node *tmp = q.front();  q.pop();
			if(tmp->left)
				q.push(tmp->left);
			if(tmp->right)
				q.push(tmp->right);
			count--;
		}
	}

}

int main(){
	node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    cout << "Height of tree is " << treeHeight(root);
	return 0;
}

