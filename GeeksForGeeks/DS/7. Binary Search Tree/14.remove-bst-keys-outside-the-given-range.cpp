// http://www.geeksforgeeks.org/remove-bst-keys-outside-the-given-range

#include <iostream>
#include "bst.h"

void deleteNodes(node *&root){
     if(root == NULL)
         return;
    deleteNodes(root->left);
    deleteNodes(root->right);
    root = NULL;
    delete(root);
}

void removeOutsideRange(node *&root, int k1, int k2){
	 if(root == NULL)
	     return;
	 if(root->data < k1){

        node *tmp = root;
        root = tmp->right;
        tmp->right == NULL;
  	    deleteNodes(tmp);
        if(root)
            removeOutsideRange(root->right, k1, k2);
     }
     else if(root->data > k2){
        node *tmp = root;
        root = tmp->left;
        tmp->left = NULL;
  	    deleteNodes(tmp);
        if(root)
            removeOutsideRange(root->left, k1, k2);
     }
  	 else {
          removeOutsideRange(root->left, k1, k2);
          removeOutsideRange(root->right, k1, k2);
     }
}

int main(){
	node* root = NULL;
    root = insert(root, 6);
    root = insert(root, -13);
    root = insert(root, 14);
    root = insert(root, -8);
    root = insert(root, 15);
    root = insert(root, 13);
    root = insert(root, 7);
 
    cout << "Inorder traversal of the given tree is: ";
    printInorder(root);
	removeOutsideRange(root, -10, 13);
 
    cout << "\nInorder traversal of the modified tree is: ";
    printInorder(root);
    getchar();
}
