// http://www.geeksforgeeks.org/find-the-largest-subtree-in-a-tree-that-is-also-a-bst

#include <iostream>
#include "bst.h"

int largestBSTUtil(node *root, int *Min, int *Max, int *max_size, bool *is_bst){
	if(root == NULL){
	    return 0;
	}
	bool left_flag = false;
	bool right_flag = false;
	int min = INT_MAX;
	*Max = INT_MIN;
	int a = largestBSTUtil(root->left, Min, Max, max_size, is_bst);
	if(*is_bst == 1 && root->data > *Max)
 	    left_flag = true;
	min = *Min;
	*Min = INT_MAX;
	int b = largestBSTUtil(root->right, Min, Max, max_size, is_bst);
	if(*is_bst == 1 && root->data < *Min)
 	    right_flag = true;
 
	if(min < *Min)
 	    *Min = min;
	if(root->data < *Min)
 	    *Min = root->data;
	if(root->data > *Max)
 	    *Max = root->data;
 	    
	if(left_flag && right_flag){
 	    if(a+b+1 > *max_size)
   		    *max_size = a+b+1;
	    return a+b+1;
	}
	else {
		 *is_bst = 0;
		 return 0;
    }


}

int largestBST(node *root){
	int Min = INT_MAX;
	int Max = INT_MIN;
	int max_size = 0;
	bool is_bst = 1;
	largestBSTUtil(root, &Min, &Max, &max_size, &is_bst);
	return max_size;
}

int main(){
    /* Let us construct the following Tree
          50
       /      \
     10        60
    /  \       /  \
   5   20    55    70
            /     /  \
          45     65    80
  */
 
  struct node *root = newNode(50);
  root->left        = newNode(10);
  root->right       = newNode(60);
  root->left->left  = newNode(5);
  root->left->right = newNode(20);
  root->right->left  = newNode(55);
  root->right->left->left  = newNode(45);
  root->right->right = newNode(70);
  root->right->right->left = newNode(65);
  root->right->right->right = newNode(80);

  /* The complete tree is not BST as 45 is in right subtree of 50.
     The following subtree is the largest BST
        60
      /  \
    55    70
   /     /  \
 45     65    80
  */
 
  printf(" Size of the largest BST is %d", largestBST(root->right));
 
  getchar();
}
