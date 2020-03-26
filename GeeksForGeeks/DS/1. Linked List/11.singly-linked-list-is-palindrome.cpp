// http://www.geeksforgeeks.org/function-to-check-if-a-singly-linked-list-is-palindrome

#include <iostream>
#include <stack>
#include "linkedList.h"

bool isPalindrome(node** left, node* right){
	if(right == NULL)
		return true;
	bool a = isPalindrome(left, right->next);
	if (!a)
		return false;
	a = ((*left)->data == right->data);
	*left = (*left)->next;	
	return a;
}

bool isPalindrome(node *head){
	stack<node*> s;
	node *slow = head;
	node *fast = head;
	while(fast && fast->next){
		s.push(slow);
		slow = slow->next;
		fast = fast->next->next;
	}
	if(fast && fast->next == NULL){
		slow = slow->next;
	}
	while(!s.empty()){
		if(s.top()->data != slow->data)
			return false;
		s.pop();
		slow = slow->next;
	}
}

int main() {
    /* Start with the empty list */
    struct node* head = NULL;
    char str[] = "abccba";
    int i;
 
    for (i = 0; str[i] != '\0'; i++) {
       push(&head, str[i]);
    }
	printList(head);
	//isPalindrome(&head, head)? printf("Is Palindrome\n\n"): printf("Not Palindrome\n\n");
	isPalindrome(head)? printf("Is Palindrome\n\n"): printf("Not Palindrome\n\n");
    return 0;
}
