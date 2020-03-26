// http://geeksquiz.com/queue-set-1introduction-and-array-implementation/

#include <iostream>
#include <climits>
#include <cstdio>
//#include <cmath>
//#include <vector>
//#include <string>
using namespace std;

struct queue{
	int front, rear, size;
	int *arr;
};

queue* createQueue(int n){
	queue *q = new queue;
	q->arr = new int[n];
	q->front = -1;
	q->rear = -1;
	q->size = n;
	return q;
}

void enqueue(queue *q, int data){
	if(q->rear == -1){
		q->front++;
		q->rear++;
		q->arr[q->rear] = data;
	}
}

int main(){
	queue* q = createQueue(100);

    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);
 
    printf("%d dequeued from queue\n", dequeue(q));
 
    printf("Front item is %d\n", front(q));

    printf("Rear item is %d\n", rear(q));
 
	return 0;
}