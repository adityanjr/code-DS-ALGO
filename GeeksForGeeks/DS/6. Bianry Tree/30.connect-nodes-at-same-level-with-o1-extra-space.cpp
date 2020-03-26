// http://www.geeksforgeeks.org/connect-nodes-at-same-level-with-o1-extra-space

#include <iostream>
using namespace std;

struct node {
	int data;
	node *right, *left, *next;
};

node *newNode(int data){
	node *n = new node;
	n->data = data;
	n->right = n->left = n->next = NULL;
	return n;
}

node *getNextRight(node *root){
	node *ptr = root->next;
	while(ptr){
		if(ptr->left)
			return ptr->left;
		if(ptr->right)
			return ptr->right;
		ptr = ptr->next;
	}
	if(ptr == NULL)
		return NULL;

}

void connectRec(node *root){
	if(root == NULL)
		return;
	if(root->next != NULL){
		connectRec(root->next);
	}
	if(root->left){
		if(root->right){
			root->left->next = root->right;
			root->right->next = getNextRight(root);
		}
		else
			root->left->next = getNextRight(root);
		connectRec(root->left);
	}
	else if(root->right) {
		root->right->next = getNextRight(root);
		connectRec(root->right);
	}
	else {
		connectRec(getNextRight(root));
	}
}

void connect(node *root){
	if(root == NULL)
		return;
	root->next = NULL;
	connectRec(root);
}

void connectIter(node *root){
	if(root == NULL)
		return;
	root->next = NULL;
	while(root){
		if(root->left){
			if(root->right){
				root->left->next = root->right;
				root->right->next = getNextRight(root);
			}
			else {
				root->left->next = getNextRight(root);
			}
			root = root->left;
		}
		else if(root->right) {
			root->right->next = getNextRight(root);
		}
		else {
			root = root->next;
		}
	}
}

int main(){
	/* Constructed binary tree is
              10
            /   \
          8      2
        /         \
      3            90
    */
    struct node *root = newNode(10);
    root->left        = newNode(8);
    root->right       = newNode(2);
    root->left->left  = newNode(3);
    root->left->left->left = newNode(11);
    root->right->right       = newNode(90);
    root->right->right->right = newNode(12);

    // Populates nextRight pointer in all nodes
    connectIter(root);

    // Let us check the values of nextRight pointers
    printf("Following are populated nextRight pointers in the tree "
           "(-1 is printed if there is no nextRight) \n");
    printf("nextRight of %d is %d \n", root->data,
           root->next? root->next->data: -1);
    printf("nextRight of %d is %d \n", root->left->data,
           root->left->next? root->left->next->data: -1);
    printf("nextRight of %d is %d \n", root->right->data,
           root->right->next? root->right->next->data: -1);
    printf("nextRight of %d is %d \n", root->left->left->data,
           root->left->left->next? root->left->left->next->data: -1);
    printf("nextRight of %d is %d \n", root->right->right->data,
           root->right->right->next? root->right->right->next->data: -1);

	return 0;
}
