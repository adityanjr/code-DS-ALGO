// http://www.geeksforgeeks.org/flatten-a-linked-list-with-next-and-child-pointers

#include <iostream>
//#include "linkedList.h"
using namespace std;

struct node{
    int data;
    struct node *next;
    struct node *child;
};
 
// A utility function to create a linked list with n nodes. The data
// of nodes is taken from arr[].  All child pointers are set as NULL
struct node *createList(int *arr, int n)
{
    struct node *head = NULL;
    struct node *p;
 
    int i;
    for (i = 0; i < n; ++i) {
        if (head == NULL)
            head = p = new node;
        else {
            p->next = new node;
            p = p->next;
        }
        p->data = arr[i];
        p->next = p->child = NULL;
    }
    return head;
}
 
// A utility function to print all nodes of a linked list
void printList(struct node *head)
{
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}
 
// This function creates the input list.  The created list is same
// as shown in the above figure
struct node *createList(void)
{
    int arr1[] = {10, 5, 12, 7, 11};
    int arr2[] = {4, 20, 13};
    //int arr3[] = {17, 6};
    //int arr4[] = {9, 8};
    //int arr5[] = {19, 15};
    //int arr6[] = {2};
    //int arr7[] = {16};
    //int arr8[] = {3};
 
    /* create 8 linked lists */
    struct node *head1 = createList(arr1, sizeof(arr1));
    struct node *head2 = createList(arr2, sizeof(arr2));
     /*struct node *head3 = createList(arr3, sizeof(arr3));
    struct node *head4 = createList(arr4, sizeof(arr4));
    struct node *head5 = createList(arr5, sizeof(arr5));
    struct node *head6 = createList(arr6, sizeof(arr6));
    struct node *head7 = createList(arr7, sizeof(arr7));
    struct node *head8 = createList(arr8, sizeof(arr8));
 */
 
    /* modify child pointers to create the list shown above */
    head1->child = head2;
   /* head1->next->next->next->child = head3;
    head3->child = head4;
    head4->child = head5;
    head2->next->child = head6;
    head2->next->next->child = head7;
    head7->child = head8;
 */
 
    /* Return head pointer of first linked list.  Note that all nodes are
       reachable from head1 */
    return head1;
}

void utils(node *head, node **tail){
	if(head == NULL)
	    return;
	if(head->child == NULL){
		utils(head->next, tail);
		return;
	}
	node *ptr = head;
	node *next = ptr->child;
	ptr->child = NULL;
	(*tail)->next = next;
	while((*tail)->next){
		(*tail) = (*tail)->next;
	}
	utils(head->next, tail);
}

void flattenList(node* head){
	node *tail = head;
	while(tail->next){
		cout<<tail->data<<" ";
		tail = tail->next;
	}
	cout<<tail->data<<'\n';
	node *ptr = head;
	//utils(head, &tail);
}

// A driver program to test above functions
int main(void){
    struct node *head = NULL;
    head = createList();
    flattenList(head);
    printList(head);
    return 0;
}
