// http://www.geeksforgeeks.org/bottom-view-binary-tree/

#include <iostream>
#include <queue>
#include <map>
#include "bt.h"

void printBottomView(node *root){
	if(root == NULL)
		return;
	queue<node*> q;
	queue<int> side;
	map<int, node*> M;
	q.push(root);
	side.push(0);
	M[0] = root;
	while(!q.empty()){
		node *tmp = q.front();  q.pop();
		int level = side.front();   side.pop();
		if(tmp->left){
			q.push(tmp->left);
			side.push(level-1);
			M[level-1] = tmp->left;
		}
		if(tmp->right){
			q.push(tmp->right);
			side.push(level+1);
			M[level+1] = tmp->right;
		}
	}
	map<int, node*>::iterator iter;
	for(iter = M.begin(); iter != M.end(); iter++){
		cout<<iter->second->data<<" ";
	}
}

int main(){
	/* Create following Binary Tree
             1
           /  \
          2    3
           \
            4
             \
              5
               \
                6*/
        node *root = newNode(1);
        root->left = newNode(2);
        root->right = newNode(3);
        root->left->right = newNode(4);
        root->left->right->right = newNode(5);
        root->left->right->right->right = newNode(6);
        root->right->left = newNode(7);
        root->right->left->left = newNode(8);
        root->right->left->left->left = newNode(9);
        printBottomView(root);
	return 0;
}

