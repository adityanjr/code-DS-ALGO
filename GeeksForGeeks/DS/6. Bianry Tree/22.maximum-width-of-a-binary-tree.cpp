// http://www.geeksforgeeks.org/maximum-width-of-a-binary-tree

#include <iostream>
#include "bt.h"

void getMaxWidthRec(node *root, int *arr, int level){
	if(root == NULL){
		return;
	}
	arr[level]++;
	getMaxWidthRec(root->left, arr, level+1);
	getMaxWidthRec(root->right, arr, level+1);
}

int getMaxWidth(node *root){
	int arr[100] = {0};
	getMaxWidthRec(root, arr, 0);
	int max = 0;
	for(int i=0; i<100; i++){
		if(arr[i] > max)
			max = arr[i];
	}
	return max;
}

int main(){
	node *root = newNode(1);
  root->left        = newNode(2);
  root->right       = newNode(3);
  root->left->left  = newNode(4);
  root->left->right = newNode(5);
  root->right->right = newNode(8);    
  root->right->right->left  = newNode(6);    
  root->right->right->right  = newNode(7);      

  /*
   Constructed bunary tree is:
          1
        /  \
       2    3
     /  \     \
    4   5     8 
              /  \
             6   7
  */  
  printf("Maximum width is %d \n", getMaxWidth(root));  
	return 0;
}