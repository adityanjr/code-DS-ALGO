/* 

The structure of the class is
class Queue {
private:
    int arr[10001];
    int front;
    int rear;

public :
    Queue(){front=0;rear=0;}
    void push(int);
    int pop();
};
 */

/* The method push to push element into the queue */
void Queue :: push(int x)
{
    if(rear > front){
        rear = front;
    }
    arr[front] = x;
    front++;
}

/*The method pop which return the element poped out of the queue*/
int Queue :: pop()
{   
    int ans = -1;
    
    if(front > rear){
        ans = arr[rear];
    }
    rear++;
    
    return ans;
}
