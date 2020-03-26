// http://www.geeksforgeeks.org/print-unique-rows

#include <iostream>
#include <cstdio>
using namespace std;

struct node{
	bool isEOC;
	node *left, *right;
};

node *newNode(){
	node *n = new node;
	n->isEOC = 0;
	n->left = n->right = NULL;
	return n;
}

bool insert(node *root, bool *a, int N){
	for(int i=0; i<N; i++){
		if(a[i]){
			if(!root->right)
				root->right = newNode();
			root = root->right;
		}
		else {
			if(!root->left)
				root->left = newNode();
			root = root->left;
		}
	}
	if(root->isEOC){
		return 0;
	}
	else {
		root->isEOC = 1;
		return 1;
	}
}

void printArray(bool *a, int N){
	for(int i=0; i<N; i++)
		cout<<a[i]<<" ";
	cout<<'\n';
}

void findUniqueRows(bool **a, int R, int C){
	node *root = newNode();
	for(int i=0; i<R; i++){
		if(insert(root, a[i], C)){
			printArray(a[i], C);
		}
	}
}

int main(){
	int R = 4, C=5;
	int M[4][5] = {{0, 1, 0, 0, 1},
        {1, 0, 1, 1, 0},
        {0, 1, 0, 0, 1},
        {1, 0, 1, 0, 0}
    };

	bool **arr;
	arr = new bool*[R];
	for(int i=0; i<R; i++){
		arr[i] = new bool[C];
		for(int j=0; j<C; j++)
			arr[i][j] = M[i][j];
	}
    findUniqueRows(arr, R, C);
	getchar();
}

