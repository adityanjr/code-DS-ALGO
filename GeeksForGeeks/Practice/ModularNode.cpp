/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/*Struture of the node of the linked list is as:
struct Node {
	int data;
	struct Node* next;
};
*/
// Your task is to complete the function
// function should return the modular Node
// if no such node is present then return -1
int modularNode(Node* head, int k)
{
	// Code here
	int curr = 1, ans = -1;
	
	while(head){
	    if(curr%k == 0){
	        ans = head->data;
	    }
	    curr++;
	    head = head->next;
	}
	
	return ans;
}
