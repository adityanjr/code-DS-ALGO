// http://www.geeksforgeeks.org/add-greater-values-every-node-given-bst

#include <iostream>
#include "bst.h"

void modifyBST(node *root, int *sum){
	if(root == NULL)
	    return;
	modifyBST(root->right, sum);
	*sum += root->data;
	root->data = *sum;
	modifyBST(root->left, sum);
}

int main(){
	/* Let us create following BST
              50
           /     \
          30      70
         /  \    /  \
       20   40  60   80 */
    struct node *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
 	int sum = 0;
    modifyBST(root, &sum);
 
    // print inoder tarversal of the modified BST
    printInorder(root);
    getchar();
}
