// http://www.geeksforgeeks.org/efficiently-implement-k-stacks-single-array/

#include <iostream>
#include <cstring>
using namespace std;

class kstack{
	int *arr;
	int *top;
	int *next;
	int free;
	public:
		kstack(int, int);
		void push(int, int);
		int pop(int);
};

kstack::kstack(int n, int k){
	arr = new int[n];
	top = new int[k];
	next = new int[n];
	free = 0;
	memset(top, -1, sizeof(top));
	for (int i=0; i<n-1; i++)
        next[i] = i+1;
    next[n-1] = -1;
}

void kstack::push(int data, int k){
	if(free == -1)
		cout<<"ERR";
	int i = free;
	free = next[i];
	next[i] = top[k];
	arr[i] = data;
	top[k] = i;
}

int kstack::pop(int k){
	if(top[k] == -1)
		return -1;
	int i = top[k];
	top[k] = next[i];
	next[i] = free;
	free = i;
	return arr[i];
}

int main(){
	int k = 3, n = 10;
    kstack ks(n, k);
 
    // Let us put some items in stack number 2
    ks.push(15, 2);
    ks.push(45, 2);
 
    // Let us put some items in stack number 1
    ks.push(17, 1);
    ks.push(49, 1);
    ks.push(39, 1);
 
    // Let us put some items in stack number 0
    ks.push(11, 0);
    ks.push(9, 0);
    ks.push(7, 0);
 
    cout << "Popped element from stack 2 is " << ks.pop(2) << endl;
    cout << "Popped element from stack 1 is " << ks.pop(1) << endl;
    cout << "Popped element from stack 0 is " << ks.pop(0) << endl;
	return 0;
}

