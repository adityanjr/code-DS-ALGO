// http://www.geeksforgeeks.org/queue-using-stacks/

#include <iostream>
#include <stack>
using namespace std;

struct queue {
	stack<int> stack1;
	stack<int> stack2;
};
// Method-1
void enQueue(queue *q, int data){
	while(!q->stack2.empty()){
	 	q->stack1.push(q->stack2.top());	q->stack2.pop();
	}
	q->stack2.push(data);
}

int deQueue(queue *q){
	while(!q->stack1.empty()){
	 	q->stack2.push(q->stack1.top());	q->stack1.pop();
	}
	int res = q->stack2.top();	q->stack2.pop();
	return res;
}

// Method -2
void enQueue1(queue *q, int data){
	q->stack1.push(data);
}

int deQueue1(queue *q){
	if(q->stack1.empty())
 	    return -1;
	else if(q->stack1.size() == 1){
		int tmp = q->stack1.top();	q->stack1.pop();
		return tmp;
	}
	int tmp = q->stack1.top();	q->stack1.pop();
	int res = deQueue1(q);
	q->stack1.push(tmp);
	return res;
}

int main(){
	/* Method-1 */
	struct queue *q = new queue;
   	enQueue(q, 1);
   	enQueue(q, 2);
   	enQueue(q, 3);    
  
   /* Dequeue items */
   printf("%d  ", deQueue(q));
   printf("%d  ", deQueue(q));
   printf("%d  ", deQueue(q));
   
   
   /* Method-2 */
	struct queue *q1 = new queue;
   	enQueue1(q1, 1);
   	enQueue1(q1, 2);
   	enQueue1(q1, 3);    
  
   /* Dequeue items */
    printf("%d  ", deQueue1(q1));
   printf("%d  ", deQueue1(q1));
   printf("%d  ", deQueue1(q1));
   /**/
	return 0;
}

