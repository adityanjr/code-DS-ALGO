// http://www.geeksforgeeks.org/iterative-tower-of-hanoi
/*Not-understand*/

#include <iostream>
#include <stack>
using namespace std;

void tohIterative(stack<int> src, stack<int> aux, stack<int> dest, int n){
	for(int i=n-1; i>=0; i--)
		src.push(i);
	
}

int main(){
	// Input: number of disks
    unsigned num_of_disks = 3;
 
    struct Stack *src, *dest, *aux;
 
    // Create three stacks of size 'num_of_disks'
    // to hold the disks
    
    stack<int> src;
    stack<int> aux;
    stack<int> dest;
    tohIterative(src, aux, dest, num_of_disks);
	return 0;
}

