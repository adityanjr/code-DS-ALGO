// http://geeksquiz.com/binary-search-tree-set-2-delete

#include <iostream>
#include "bst.h"

node *deleteNode(node *root, int key){
	if(root == NULL)
		return NULL;
	if(key < root->data){
		root->left = deleteNode(root->left, key);
	}
	else if(key > root->data){
		root->right = deleteNode(root->right, key);
	}
	else {
		if(root->left == NULL){
			node *res = root->right;
			delete(root);
			return res;
		}
		else if(root->right == NULL){
			node *res = root->left;
			delete(root);
			return res;
		}
		else {
			node *ptr = root->right;
			while(ptr->left){
				ptr = ptr->left;
			}
			root->data = ptr->data;
			root->right = deleteNode(root->right, ptr->data);
		}
	}
	return root;
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
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);
    printf("Inorder traversal of the given tree \n");
    printInorder(root);
 
    printf("\nDelete 20\n");
    root = deleteNode(root, 20);
    printf("Inorder traversal of the modified tree \n");
    printInorder(root);
 
    printf("\nDelete 30\n");
    root = deleteNode(root, 30);
    printf("Inorder traversal of the modified tree \n");
    printInorder(root);
 
    printf("\nDelete 50\n");
    root = deleteNode(root, 50);
    printf("Inorder traversal of the modified tree \n");
    printInorder(root);
    getchar();
}
