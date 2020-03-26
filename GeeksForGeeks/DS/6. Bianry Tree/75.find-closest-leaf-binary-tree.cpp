// http://www.geeksforgeeks.org/find-closest-leaf-binary-tree

#include <iostream>
#include "bt.h"

int findClosestDown(node *root){
	if(root == NULL)
		return INT_MAX;
	if(!root->left && !root->right)
		return 0;
	return 1 + min(findClosestDown(root->left), findClosestDown(root->right));
}

int findClosestUtil(node *root, node **ance, int k, int level){
	if(root == NULL)
		return INT_MAX;
	int res = INT_MAX;
	if(root->data == k){
		int a = findClosestDown(root);
		for(int i=level-1; i>=0; i--){
			res = min(res, level - i + findClosestDown(ance[i]));
		}
		return min(res, a);
	}
	ance[level] = root;
	level++;
	return min(findClosestUtil(root->left, ance, k, level), findClosestUtil(root->right, ance, k, level));
}

int findClosest(node *root, int k){
	node *ance[100];
	return findClosestUtil(root, ance, k, 0);
}

// For all nodes
int find(node* root, int level, map<node*, int> &m){
	if(root == NULL)
		return INT_MAX;
	if(!root->left && !root->right){
		return 0;
	}
	int l = find(root->left, level+1, m);
	if(l != INT_MAX)
		l++;
	int r = find(root->right, level+1, m);
	if(r != INT_MAX)
		r++;
	if(m.count(root)){
		m[root] = min(m[root], min(l, r));
	}
	else{
		m[root] = min(l, r);
	}
	return m[root];
}
	
void reset(node *root, map<node*, int> &m){
	if(root == NULL)
		return;
	if(root->left){
		if(m[root->left] > m[root]+1)
			m[root->left] = m[root]+1;
	}
	if(root->right){
		if(m[root->right] > m[root]+1)
			m[root->right] = m[root]+1;
	}
	reset(root->left, m);
	reset(root->right, m);
}

void findClosest(node *root){
	map<node*, int> m;
	find(root, 0, m);
	reset(root, m);
	map<node*, int>::iterator iter = m.begin();
	for(;iter != m.end(); iter++){
		cout<<iter->first->data<<" "<<iter->second<<'\n';
	}
}
// End here

int main(){
	node *root        = newNode(1);
    root->left               = newNode(2);
    root->right              = newNode(3);
    root->right->left        = newNode(4);
    root->right->right       = newNode(5);
    root->right->left->left  = newNode(6);
    root->right->left->left->left  = newNode(7);
    root->right->left->left->right = newNode(8);
    root->right->right->right      = newNode(9);
    root->right->right->right->left = newNode(10);

    int k = 8;
    cout<<findClosestDown(root);
    cout << "Distace of the closest key from " << k << " is "
         << findClosest(root, k) << endl;
    k = 3;
    cout << "Distace of the closest key from " << k << " is "
         << findClosest(root, k) << endl;
    k = 5;
    cout << "Distace of the closest key from " << k << " is "
         << findClosest(root, k) << endl;
    k = 2;
    cout << "Distace of the closest key from " << k << " is "
         << findClosest(root, k) << endl;
	return 0;
}

