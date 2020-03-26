// http://www.geeksforgeeks.org/design-a-stack-with-find-middle-operation

#include <iostream>
#include <cstdio>
using namespace std;

struct node{
	int data;
	node *next;
	node *prev;
};

struct myStack{
	node *head;
	node *middle;
	int size;
};

myStack* createMyStack(){
	myStack *tmp = new myStack;
	tmp->head = NULL;
	tmp->middle = NULL;
	tmp->size = 0;
	return tmp;
}

void push(myStack *ms, int data){
	node *n = new node;
	n->data = data;
	n->next = NULL;
	n->prev = NULL;
	if(ms->size == 0){
		ms->head = n;
		ms->middle = n;
		ms->size++;
		return;
	}
	ms->size++;
	n->next = ms->head;
	ms->head->prev = n;
	ms->head = n;
	if(ms->size%2){
		ms->middle = ms->middle->prev;
	}
}


int pop(myStack *ms){
	if(ms->size == 0){
		return -1;
	}
	if(ms->size%2){
		ms->middle = ms->middle->next;
	}
	ms->size--;
	node *tmp = ms->head;
	int res = tmp->data;
	ms->head = ms->head->next;
	delete(tmp);
	return res;
}

int findMiddle(myStack *ms){
	return ms->middle->data;
}

int main(){
	myStack *ms = createMyStack();
    push(ms, 11);
    push(ms, 22);
    push(ms, 33);
    push(ms, 44);
    push(ms, 55);
    push(ms, 66);
    push(ms, 77);
 
    printf("Item popped is %d\n", pop(ms));
    printf("Item popped is %d\n", pop(ms));
    printf("Middle Element is %d\n", findMiddle(ms));
//	cout<<ms->middle->data;
	return 0;
}

