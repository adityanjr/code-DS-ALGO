/*
    This problem was asked by Apple.

    Implement a queue using two stacks. Recall that a queue is a FIFO (first-in, first-out) data structure with the following methods: 

        enqueue, which inserts an element into the queue, 
        
        and dequeue, which removes it.
 */
#include <bits/stdc++.h>
using namespace std;
template<class Object>
struct Queue{
    private:
        stack< Object > enq;
        stack< Object > deq;
    public:
        void enqueue( Object value ) {
            enq.push( value );
        }

        Object dequeue( void ) {
            while( !enq.empty() ) {
                deq.push( enq.top() );
                enq.pop();
            }

            Object element = deq.top();
            deq.pop();

            while( !deq.empty() ) {
                enq.push( deq.top() );
                deq.pop();
            }

            return element;
        }
            
};
int main(void){
    Queue<int> q;
    q.enqueue(100);
    q.enqueue(200);
    cout<<q.dequeue()<<'\n';
    q.enqueue(400);
    q.enqueue(500);
    cout<<q.dequeue()<<'\n';
    return 0;
}
