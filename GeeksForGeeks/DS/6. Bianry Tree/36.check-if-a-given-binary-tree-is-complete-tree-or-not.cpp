// http://www.geeksforgeeks.org/check-if-a-given-binary-tree-is-complete-tree-or-not/

#include <iostream>
#include <queue>
#include "bt.h"

bool isCompleteBT(node *root){
	if(root == NULL)
		return true;
	queue<node*> q;
	q.push(root);
	bool flag = false;
	while(!q.empty()){
		node *tmp = q.front();  q.pop();
		if(tmp->left){
			if(flag)
				return false;
			q.push(tmp->left);
		}
		else
			flag = true;

        if(tmp->right){
        	if(flag)
				return false;
			q.push(tmp->right);
        }
		else
			flag = true;
	}
	return true;
}

int main(){
	/* Let us construct the following Binary Tree which
      is not a complete Binary Tree
            1
          /   \
         2     3
        / \     \
       4   5     6
    */

  struct node *root  = newNode(1);
  root->left         = newNode(2);
  root->right        = newNode(3);
  root->left->left   = newNode(4);
  root->left->right  = newNode(5);
  root->right->right = newNode(6);

  if ( isCompleteBT(root) == true )
      printf ("Complete Binary Tree");
  else
      printf ("NOT Complete Binary Tree");
	return 0;
}

