// http://www.geeksforgeeks.org/find-if-there-is-a-triplet-in-bst-that-adds-to-0

#include <iostream>
#include "bst.h"

node *rightMost(node *head){
	while(head && head->right)
		head = head->right;
	return head;
}

node *convertToDLL(node *root){
	if(root == NULL)
		return NULL;
	node *l = convertToDLL(root->left);
	node *lr = rightMost(l);
	root->left = lr;
	if(lr)
		lr->right = root;
	node *r = convertToDLL(root->right);
	root->right = r;
	if(r)
		r->left = root;
	if(l == NULL)
		return root;
	return l;
}

bool isDoubletPresent(node *head, int k){
	if(head == NULL)
		return false;
	node *tail = head;
	while(tail->right){
		tail = tail->right;
	}
	while(head != tail){
		int tmp = head->data + tail->data;
		if(tmp == k)
			return true;
		else if(tmp < k)
			head = head->right;
		else
			tail = tail->left;
	}
	return false;
}

void printList(node *head){
	while(head){
		cout<<head->data<<" ";
		head = head->right;
	}
}

bool isTripletPresent(node *root){
	if(root == NULL)
		return false;
	node *head = convertToDLL(root);
	node *ptr = head;
	while(ptr && ptr->data < 0 && ptr->right && ptr->right->right){
		if(isDoubletPresent(ptr->right, -1*ptr->data)){
			return true;
		}
		ptr = ptr->right;
	}
	return false;
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
    if (isTripletPresent(root))
        printf("Present");
    else
        printf("Not Present");
	return 0;
}

