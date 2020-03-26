// http://www.geeksforgeeks.org/find-next-right-node-of-a-given-key

#include <iostream>
#include <queue>
#include "bt.h"

void test(node *root, int k){
	if(root == NULL)
		return;
	queue<node*> q;
	q.push(root);
	if(root->data ==k)
		return;
	bool flag = false;
	while(!q.empty()){
		if(flag)
			return;
		int count = q.size();
		while(count){
			node *tmp = q.front();  q.pop();
			if(flag){
				cout<<tmp->data<<'\n';
				return;
			}
			if(tmp->data == k)
				flag = true;

			if(tmp->left)
				q.push(tmp->left);
			if(tmp->right)
				q.push(tmp->right);
			count--;
		}
	}
}

int main(){
	node *root = newNode(10);
    root->left = newNode(2);
    root->right = newNode(6);
    root->right->right = newNode(5);
    root->left->left = newNode(8);
    root->left->right = newNode(4);

    test(root, 10);
    test(root, 2);
    test(root, 6);
    test(root, 5);
    test(root, 8);
    test(root, 4);
	return 0;
}

