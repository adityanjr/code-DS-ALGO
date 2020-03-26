// http://www.geeksforgeeks.org/given-linked-list-representation-of-complete-tree-convert-it-to-linked-representation

#include <iostream>
#include "bt.h"

struct LNode {
    int data;
    LNode* next;
};

void push(LNode **head, int data){
	LNode *r = new LNode;
	r->data = data;
	r->next = NULL;
	if(*head == NULL){
		*head = r;
		return;
	}
	r->next = *head;
	*head = r;
}

void convertList2Binary(LNode *head, node **root, queue<node*> &q){
	if(head == NULL)
		return;
	if(!q.empty()){
		node *tmp = q.front();
		node *n = newNode(head->data);
		if(tmp->left == NULL || tmp->right == NULL){
			if(tmp->left == NULL){
				tmp->left = n;
			}
			else
				tmp->right = n;
			q.push(n);
		}
		else{
			q.pop();
			convertList2Binary(head, root, q);
			return;
		}
	}
	else{
		*root = newNode(head->data);
		q.push(*root);
	}
	convertList2Binary(head->next, root, q);
}

// Linked list to root without linked list struct
void convertList2Binary1(node *root){
	if(root == NULL)
		return;
	queue<node*> q;
	node *tmp = root->right;
	root->right = root->left = NULL;
	q.push(root);
	root = tmp;
	while(root){
		node *ptr = q.front();  q.pop();
		ptr->left = root;
		tmp = root->right;
		root->right = root->left = NULL;
		q.push(root);
		root = tmp;
		if(root){
			ptr->right = root;
			tmp = root->right;
			root->right = root->left = NULL;
			q.push(root);
			root = tmp;
		}
	}
}

int main(){
	LNode* head = NULL;
    push(&head, 36);  /* Last node of Linked List */
    push(&head, 30);
    push(&head, 25);
    push(&head, 15);
    push(&head, 12);
    push(&head, 10); /* First node of Linked List */

    node *root;
    queue<node*> q;
    convertList2Binary(head, &root, q);

    cout << "Inorder Traversal of the constructed Binary Tree is: \n";
    printInorder(root);
	return 0;
}

