// http://www.geeksforgeeks.org/get-level-of-a-node-in-a-binary-tree

#include <iostream>
#include "bt.h"

int getLevel(node *root, int d){
	if(root	==	NULL)
		return 0;
	if(root->data == d)
		return 1;
	else {
		int l = getLevel(root->left, d);
		int r = getLevel(root->right, d);
		if(l != 0)
			return 1+l;
		else if(r != 0)
			return 1+r;
		else
			return 0;
	}
}

int main(){
	node *root = new struct node;
    int x;

    /* Constructing tree given in the above figure */
    root = newNode(3);
    root->left = newNode(2);
    root->right = newNode(5);
    root->left->left = newNode(1);
    root->left->right = newNode(4);

    for (x = 1; x <=5; x++) {
      int level = getLevel(root, x);
      if (level)
        printf(" Level of %d is %d\n", x, getLevel(root, x));
      else
        printf(" %d is not present in tree \n", x);

    }
	return 0;
}

