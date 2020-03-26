// http://geeksquiz.com/queue-set-2-linked-list-implementation/

#include<iostream>
using namespace std;

struct node{
	int data;
	node* next;
};

struct queue {
	node *front, *rear;
	
};

queue *createQueue(){
	  queue *n = new queue;
	  n->front = n->rear = NULL;
	  return n;
}

void enQueue(queue *q, int data){
	node *n = new node;
	n->data = data;
	n->next = NULL;
	if(q->rear == NULL){
		q->rear = q->front = n;
		return;
	}
	q->rear->next = n;
	q->rear = q->rear->next;
}

int deQueue(queue *q){
	if(q->rear == NULL)
	   return -1;
    int res = q->front->data;
    node *del = q->front;
    if(q->front == q->rear){
    	q->front = q->rear = NULL;
	}
	else {
		q->front = q->front->next;
	}
	delete(del);
	return res;
}

int main(){
	queue *q = createQueue();
    enQueue(q, 10);
    enQueue(q, 20);
    deQueue(q);
    deQueue(q);
    enQueue(q, 30);
    enQueue(q, 40);
    enQueue(q, 50);
    int n = deQueue(q);
    if (n != NULL)
      printf("Dequeued item is %d", n);
  
	return 0;
}

