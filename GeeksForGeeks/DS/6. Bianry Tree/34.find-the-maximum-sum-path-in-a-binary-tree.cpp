// http://www.geeksforgeeks.org/find-the-maximum-sum-path-in-a-binary-tree

#include <iostream>
#include <climits>
#include "bt.h"

bool printPath(node *root, node *target){
	if(root == NULL)
		return false;
	if(root == target || printPath(root->left, target) || printPath(root->right, target)){
		cout<<root->data<<" ";
		return true;
	}
	return false;
}

void maxSumPathRec(node *root, int sum, int *Max, node **target){
	if(root == NULL)
		return;
	sum += root->data;
	maxSumPathRec(root->left, sum, Max, target);
	maxSumPathRec(root->right, sum, Max, target);
	if(root->left == NULL && root->right == NULL){
		if(sum > *Max){
			*Max = sum;
			*target = root;
		}
	}
}

int maxSumPath(node *root){
	if(root == NULL)
		return 0;
	int Max = INT_MIN;
	node *target;
	maxSumPathRec(root, 0, &Max, &target);
	printPath(root, target);
	return Max;
}

int main(){
	node *root = NULL;
 
    /* Constructing tree given in the above figure */
    root = newNode(10);
    root->left = newNode(-2);
    root->right = newNode(7);
    root->left->left = newNode(8);
    root->left->right = newNode(-4);
 
    printf ("Following are the nodes on the maximum sum path \n");
    int sum = maxSumPath(root);
    printf ("\nSum of the nodes is %d ", sum);
	return 0;
}