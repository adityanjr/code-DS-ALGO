// http://www.geeksforgeeks.org/check-if-a-binary-tree-is-subtree-of-another-binary-tree/

#include <iostream>
#include "bt.h"

bool isSimilar(node *r1, node *r2){
	if(r1 == NULL && r2 == NULL)
		return true;
	if(r1 == NULL || r2 == NULL)
		return false;
	if(r1->data == r2->data && isSimilar(r1->left, r2->left) && isSimilar(r1->right, r2->right))
		return true;
	return false;
}

bool isSubTree(node *T, node *S){
	if(T == NULL)
		return false;
	if(T->data == S->data && isSimilar(T, S))
		return true;
	else{
		return isSubTree(T->left, S) || isSubTree(T->right, S);
	}
}

int main(){
	/* Construct the following tree
              26
            /   \
          10     3
        /    \     \
      4      6      3
       \
        30
    */
    struct node *T        = newNode(26);
    T->right              = newNode(3);
    T->right->right       = newNode(3);
    T->left               = newNode(10);
    T->left->left         = newNode(4);
    T->left->left->right  = newNode(30);
    T->left->right        = newNode(6);

    /* Construct the following tree
          10
        /    \
      4      6
       \
        30
    */
    struct node *S    = newNode(10);
    S->right          = newNode(6);
    S->left           = newNode(4);
    S->left->right    = newNode(30);


    if (isSubTree(T, S))
        printf("Tree S is subtree of tree T");
    else
        printf("Tree S is not a subtree of tree T");
        
	return 0;
}

