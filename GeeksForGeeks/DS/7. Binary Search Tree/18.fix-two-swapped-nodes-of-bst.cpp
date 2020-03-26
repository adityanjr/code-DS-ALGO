// http://www.geeksforgeeks.org/fix-two-swapped-nodes-of-bst

#include <iostream>
#include "bst.h"

void correct(node *root, node **first, node **second, node **last, node **prev){
	if(root == NULL)
		return;
	correct(root->left, first, second, last, prev);
	if(!(*prev))
		*prev = root;
	cout<<root->data<<" "<<(*prev)->data<<'\n';
	if(root->data < (*prev)->data){
		if(*first == NULL){
			*first = *prev;
			*second = root;
		}
		else {
			*last = root;
			return;
		}
	}
	*prev = root;
	correct(root->right, first, second, last, prev);
}

void correctBST(node *root){
	node *first = NULL, *second = NULL, *last = NULL;
	node *prev = NULL;
	correct(root, &first, &second, &last, &prev);
	if(last){
		int tmp = last->data;
		last->data = first->data;
		first->data = tmp;
	}
	else {
		int tmp = second->data;
		second->data = first->data;
		first->data = tmp;
	}
}

// itertive
void correctBST1(node *root){
    if(root == NULL){
        return;
    }
    node *prev=NULL;
    node *one=NULL, *two=NULL;
    node *onepost=NULL;
    while(root){
        if(root->left == NULL){
            if(prev && root->data < prev->data){
                if(one == NULL){
                    one = prev;
                    onepost = root;
                }
                else
                    two = root;
            }
            prev = root;                //cout<<root->data<<" ";
            root = root->right;
        }
        else{
            node *ptr = root->left;
            while(ptr->right && ptr->right != root)
                ptr = ptr->right;
            if(ptr->right == NULL){
                ptr->right = root;
                root = root->left;
            }
            else {
                ptr->right = NULL;
                if(prev && root->data < prev->data){
                    if(one == NULL){
                        one = prev;
                        onepost = root;
                    }
                    else
                        two = root;
                }
                prev = root;    //cout<<root->data<<" ";
                root = root->right;
            }
        }
    }
    if(one && two) {
        int tmp = one->data;
        one->data = two->data;
        two->data = tmp;
    }
    else if(one != NULL){
        int tmp = one->data;
        one->data = onepost->data;
        onepost->data = tmp;
    }
}

int main(){
	/*   6
        /  \
       10    2
      / \   / \
     1   3 7  12
     10 and 2 are swapped
    */

    struct node *root = newNode(6);
    root->left        = newNode(10);
    root->right       = newNode(2);
    root->left->left  = newNode(1);
    root->left->right = newNode(3);
    root->right->right = newNode(12);
    root->right->left = newNode(7);

    printf("Inorder Traversal of the original tree \n");
    printInorder(root);

    correctBST(root);

    printf("\nInorder Traversal of the fixed tree \n");
    printInorder(root);
	return 0;
}

