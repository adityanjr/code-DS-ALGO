// http://www.geeksforgeeks.org/construct-tree-from-given-inorder-and-preorder-traversal

#include <iostream>
#include <algorithm>
#include "bt.h"

int search(char arr[], int strt, int end, char value){
  int i;
  for(i = strt; i <= end; i++)
  {
    if(arr[i] == value)
      return i;
  }
}

node *buildTree(char *in, char *pre, int start, int end){
	static int index = 0;

	if(start>end)
		return NULL;

	node *n = newNode(pre[index++]);
	if(start == end)
    	return n;
	
	int i = search(in, start, end, n->data);
	n->left = buildTree(in, pre, start, i-1);
	n->right = buildTree(in, pre, i+1, end);
	return n;
	
}

int main(){
	char in[] = {'D', 'B', 'E', 'A', 'F', 'C'};
  	char pre[] = {'A', 'B', 'D', 'E', 'C', 'F'};
  	int len = sizeof(in)/sizeof(in[0]);
  	node *root = buildTree(in, pre, 0, len - 1);
 
  /* Let us test the built tree by printing Insorder traversal */
  printf("\n Inorder traversal of the constructed tree is \n");
  printInorder(root);
	return 0;
}

