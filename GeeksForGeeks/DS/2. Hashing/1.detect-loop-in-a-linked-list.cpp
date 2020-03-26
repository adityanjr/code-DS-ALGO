// http://www.geeksforgeeks.org/write-a-c-function-to-detect-loop-in-a-linked-list/

#include <iostream>
#include <map>
using namespace std;

struct node
{
    int data;
    struct node* next;
};

void push(node** head_ref, int data){
    /* allocate node */
    node *new_node = new node;
 
    /* put in the data  */
    new_node->data  = data;
 
    /* link the old list off the new node */
    new_node->next = (*head_ref);
 
    /* move the head to point to the new node */
    (*head_ref)    = new_node;
}

void detectloop(node *head){
	map<node*, bool> Map;
	node *ptr = head;
	while(ptr){
		if(Map.count(ptr)>0){
			cout<<"cycle";
			return;
		}
		Map[ptr] = 1;//.insert(pair<node*, bool>(*ptr, true));
		ptr = ptr->next;
	}
	cout<<"no-cycle";
}

int main(){
  /* Start with the empty list */
  struct node* head = NULL;
 
  push(&head, 20);
  push(&head, 4);
  push(&head, 15);
  push(&head, 10);
 
  /* Create a loop for testing */
  head->next->next->next->next = head;
  detectloop(head);
 
}
