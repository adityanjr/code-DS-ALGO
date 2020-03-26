// http://www.geeksforgeeks.org/populate-inorder-successor-for-all-nodes

#include <iostream>
using namespace std;

struct node {
	int data;
	node *left, *right, *next;
};

node *newNode(int data){
	node *n = new node;
	n->data = data;
	n->right = n->left = n->next = NULL;
	return n;
}

// (root, NULL) -> main
node *funct(node *root, node *tail){
	if(root == NULL && tail)
		return tail;
	if(root == NULL)
		return NULL;
	root->next = funct(root->right, tail);
	return funct(root->left, root);
}

int main(){
	/* Constructed binary tree is
              10
            /   \
          8      12
        /
      3
    */
    struct node *root = newNode(10);
    root->left        = newNode(8);
    root->right       = newNode(12);
    root->right->left = newNode (11);
    root->left->left  = newNode(3);

    // Populates nextRight pointer in all nodes
    node *head = populateNext(root);

    // Let us see the populated values
    while(head)
    {
        // -1 is printed if there is no successor
        printf("Next of %d is %d \n", head->data, head->next? head->next->data: -1);
        head = head->next;
    }

	return 0;
}

