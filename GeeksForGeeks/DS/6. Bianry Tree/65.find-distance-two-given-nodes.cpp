// http://www.geeksforgeeks.org/find-distance-two-given-nodes/

#include <iostream>
#include "bt.h"

bool findPath(node *root, vector<int> &path, int k){
	if(root == NULL)
		return false;
	path.push_back(root->data);
	if(root->data == k)
		return true;
	if(root->left && findPath(root->left, path, k) || root->right && findPath(root->right, path, k))
		return true;
	path.pop_back();
	return false;
}

int findDistance(node *root, int k1, int k2){
	if(root == NULL)
		return -1;
	vector<int> path1, path2;
	findPath(root, path1, k1);
	findPath(root, path2, k2);
	int i=0;
	for(; i<path1.size() && i<path2.size(); i++){
		if(path1[i] != path2[i])
			break;
	}
	return path1.size()-i + path2.size()-i;
}

/* LCA method */
/*LCA*/
bool find(node *root, int n){
	if(root == NULL)
		return false;
	if(root->data == n)
		return true;
	if(find(root->left, n) || find(root->right, n)){
		return 1;
	}
	return 0;
}

node *LCA(node *root, int n1, int n2){
	if(root == NULL)
		return NULL;
	if(root->data == n1 || root->data == n2){
		return root;
	}
	node *l = LCA(root->left, n1, n2);
	node *r = LCA(root->right, n1, n2);
	if(l && r){
		return root;
	}
	return ((l != NULL) ? l : r);
}

node *findLCA(node *root, int n1, int n2){
	node *res = LCA(root, n1, n2);
	if(res->data != n1 && res->data != n2)
		return res;
	if(res->data == n1){
		return (find(res, n2) ? res : NULL);
	}
	return (find(res, n1) ? res : NULL);
}
/*End*/

void findLevel(node *root, int n1, int n2, int n3, int &d1, int &d2, int &d3, int level){
	if(root == NULL)
		return;
	if(root->data == n1){
		d1 = level;
	}
	else if(root->data == n2){
		d2 = level;
	}
	else if(root->data == n3){
		d3 = level;
	}
	findLevel(root->left, n1, n2, n3, d1, d2, d3, level+1);
	findLevel(root->right, n1, n2, n3, d1, d2, d3, level+1);
}

int findDistance(node *root, int n1, int n2){
    node *lca = findLCA(root, n1, n2);
    int d1, d2, l;
	findLevel(root, n1, n2, lca->data, d1, d2, l, 0);
    if (d1 != -1 && d2 != -1)
           return d1+d2-2*l;
    return -1;
}

int main(){
	node * root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->left->right = newNode(8);
    cout << "Dist(4, 5) = " << findDistance(root, 4, 5);
    cout << "\nDist(4, 6) = " << findDistance(root, 4, 6);
    cout << "\nDist(3, 4) = " << findDistance(root, 3, 4);
    cout << "\nDist(2, 4) = " << findDistance(root, 2, 4);
    cout << "\nDist(8, 5) = " << findDistance(root, 8, 5);
	return 0;
}

