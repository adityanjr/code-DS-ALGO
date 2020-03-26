// http://www.geeksforgeeks.org/custom-tree-problem

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

#define A int('a')

struct node {
	char data;
	node *left, *right;
};

node* newNode(char data){
	node *n = new node;
	n->data = data;
	n->left = n->right = NULL;
}

node **createTree(string *a, int n){
	node **tnode;
	tnode = new node*[26];
	for(int i=0; i<26; i++)
		tnode[i] = NULL;
	for(int i=0; i<n; i++){
		char fir = a[i][0];
		char sec = a[i][2];

		if(tnode[int(fir)-A] == NULL)
			tnode[int(fir)-A] = newNode(fir);
		if(tnode[int(sec)-A] == NULL)
			tnode[int(sec)-A] = newNode(sec);

		if(tnode[int(fir)-A]->left == NULL){
			tnode[int(fir)-A]->left = tnode[int(sec)-A];
		}
		else {
			tnode[int(fir)-A]->right = tnode[int(sec)-A];
		}
	}
	return tnode;
}

void printNodes(node *root, int level){
	if(root == NULL)
		return;
	string tmp = "   |";
	string s = "";
	for(int i=0; i<level; i++)
		s = s + tmp;

	cout<<s<<"-->"<<root->data<<'\n';
	printNodes(root->left, level+1);
	printNodes(root->right, level+1);
}

void printForest(string *a, int n){
	node **arr = createTree(a, n);
	node *root = arr[0];
	printNodes(root, 0);
}

int main(){
	//string arr[] = {"a b", "b c", "b d", "a e"};
	string arr[] = {"a b", "a g", "b c", "c d", "d e", "c f", "z y", "y x", "x w"};
	printForest(arr, sizeof(arr)/sizeof(arr[0]));
	return 0;
}

