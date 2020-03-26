// http://www.geeksforgeeks.org/median-of-stream-of-integers-running-integers/

#include <iostream>
#include <algorithm>
#include "array.h"

#define MAX_HEAP_SIZE (128)

//For min heap
bool compare(int a, int b){
	return (a>b);
}

int median(int *minH, int *maxH, int n, int m){
	if(n==m){
		return (minH[0]+maxH[0])/2;
	}
	else if(n>m)
		return minH[0];
	return maxH[0];
}

void balance(int *maxHeap, int *minHeap, int &k, int &l){
	if(abs(k-l) < 2 && maxHeap[0] <= minHeap[0])
		return;
	if(abs(k-l) < 2){
		swap(&maxHeap[0], &minHeap[0]);
		return;
	}
	else if(k < l){
		int tmp = minHeap[0];
		pop_heap(minHeap, minHeap+l);
		l--;
		maxHeap[k] = tmp;
		push_heap(maxHeap, maxHeap+k);
		k++;
	}
	else {
		int tmp = maxHeap[0];
		pop_heap(maxHeap, maxHeap+k);
		k--;
		maxHeap[l] = tmp;
		push_heap(minHeap, minHeap+l);
		l++;
	}
	balance(maxHeap, minHeap, k, l);
}

void push(int *maxHeap, int *minHeap, int &k, int &l, int x){
	if(k <= l) {
		maxHeap[k] = x;
		k++;
		push_heap(maxHeap, maxHeap+k);
	}
	else{
		minHeap[l] = x;
		l++;
		push_heap(minHeap, minHeap+l, compare);
	}
	balance(maxHeap, minHeap, k, l);
}

void printMedian(int *a, int n){
	int maxHeap[MAX_HEAP_SIZE];
	int minHeap[MAX_HEAP_SIZE];
	int k=1, l=1;
	maxHeap[0] = min(a[0], a[1]);
	minHeap[0] = max(a[0], a[1]);
	cout<<a[0]<<"-->"<<a[0]<<'\n';
	cout<<a[1]<<"-->"<<(a[0]+a[1])/2<<'\n';
	for(int i=2; i<n; i++){
		push(maxHeap, minHeap, k, l, a[i]);
		cout<<a[i]<<"-->"<<median(maxHeap, minHeap, k, l)<<'\n';
	}
	//cout<<k<<" "<<l<<'\n';
	//printArray(minHeap, l);
	//printArray(maxHeap, k);
}

int main(){
    int A[] = {5, 15, 1, 3, 2, 8, 7, 9, 10, 6, 11, 4};
    int size = sizeof(A)/sizeof(int);
    // In lieu of A, we can also use data read from a stream
    printMedian(A, size);
    return 0;
}
