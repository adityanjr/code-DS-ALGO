// http://www.geeksforgeeks.org/counting-inversions

#include <iostream>
#include "array.h"

struct node {
	int data;
	node *left, *right;
	int rc;
};

int insert(node **root, int data){
	int count = 0;
	node *tmp = new node;
	tmp->data = data;
	tmp->left = NULL;
	tmp->right = NULL;
	tmp->rc = 0;
	if(*root == NULL){
		*root = tmp;
		return 0;
	}
	node *ptr = *root;
	node *prev = NULL;
	bool left;
	while(ptr){
		if(ptr->data > data) {
			left = true;
			count += (1 + ptr->rc);
			prev = ptr;
			ptr = ptr->left;
		}
		else {
			left = false;
			ptr->rc++;
			prev = ptr;
			ptr = ptr->right;
		}
	}
	if(left){
		prev->left = tmp;
	}
	else {
		prev->right = tmp;
	}
	return count;
}

void getInvCount(int *a, int n){
	node *root = NULL;
	int count = 0;
	for(int i=0; i<n; i++){
		int tmp = insert(&root, a[i]);
		count += tmp;
	}
	cout<<count;
}

int main(){
	int arr[] = {5, 4, 3, 2, 1};
	//printf(" Number of inversions are %d \n", getInvCount(arr, 5));
	getInvCount(arr, 5);
}
