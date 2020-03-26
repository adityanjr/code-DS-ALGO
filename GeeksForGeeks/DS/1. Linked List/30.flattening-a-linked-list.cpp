// http://www.geeksforgeeks.org/flattening-a-linked-list/

#include <iostream>
#include <climits>
#include <cstdio>
//#include <cmath>
//#include <vector>
//#include <string>
using namespace std;

struct node {
	int data;
	node *right, *down;
};

void push(node **head, int data){
	node *p = new node;
	p->data = data;
	p->down = *head;
	p->right = NULL;
	*head = p;
}

void printList(node *head){
	node *ptr = head;
	while(ptr){
		cout<<ptr->data<<" ";
		ptr = ptr->down;
	}
	cout<<'\n';
}

node* merge(node *head1, node* head2) {
	if(head1 && head2){
		node *tmp, *t;
		if(head1->data < head2->data){
			tmp = head1;
			t = merge(head1->down, head2);
		}
		else {
			tmp = head2;
			t = merge(head1, head2->down);
		}
		tmp->down = t;
		return tmp;
	}
	else if(head1) {
		return head1;
	}
	else {
		return head2;
	}
}

node* flatten(node *root){
	if(root == NULL || root->right == NULL)
		return root;
	node *head = NULL;
	node *ptr = root;
	while(ptr){
		node *tmp = ptr;
		ptr = ptr->right;
		head = merge(head, tmp);

	}
	return head;
}

int main()
{
    node* root = NULL;
 
    /* Let us create the following linked list
       5 -> 10 -> 19 -> 20
       |    |     |     |
       V    V     V     V
       7    20    22    35
       |          |     |
       V          V     V
       8          50    40
       |                |
       V                V
       30               45
    */
    push( &root, 30 );
    push( &root, 8 );
    push( &root, 7 );
    push( &root, 5 );
 
    push( &( root->right ), 20 );
    push( &( root->right ), 10 );
 
    push( &( root->right->right ), 50 );
    push( &( root->right->right ), 22 );
    push( &( root->right->right ), 19 );
 
    push( &( root->right->right->right ), 45 );
    push( &( root->right->right->right ), 40 );
    push( &( root->right->right->right ), 35 );
    push( &( root->right->right->right ), 20 );

    // Let us flatten the list
    root = flatten(root);
    //cout<<root->data;
 
    // Let us print the flatened linked list
    printList(root);
 
    return 0;
}