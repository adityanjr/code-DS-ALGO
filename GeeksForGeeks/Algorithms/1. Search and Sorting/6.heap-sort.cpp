// http://geeksquiz.com/heap-sort/
#include <iostream>
#include <climits>
#include <cstdio>
using namespace std;

void swap(int *a, int *b){
	int tmp = *a;
	*a = *b;
	*b = tmp;	
}

void printArray(int a[], int start, int end) {
	for (int i=start; i<=end; i++) {
		cout<<a[i]<<" ";
	}
	cout<<'\n';
}

struct maxHeap {
	int size;
	int* arr;
};

void maxHeapify(maxHeap *mh, int ind) {
	int largest = ind;
	int left = (ind<<1)+1;	//2*ind+1
	int right = (ind<<1)+2;

	if(right < mh->size && mh->arr[right] > mh->arr[largest])
		largest = right;
	if(left < mh->size && mh->arr[left] > mh->arr[largest])
		largest = left;
	if(largest != ind) {
		swap(&mh->arr[largest], &mh->arr[ind]);
		maxHeapify(mh, largest);
	}
}

struct maxHeap* createHeap(int *arr, int size) {
	maxHeap* mh = new maxHeap;
	mh->size = size;
	mh->arr = arr;
	for (int i = (mh->size - 2)/2; i >= 0; --i) {
		maxHeapify(mh, i);
	}
	return mh;
}

void heapSort(int *arr, int start, int end) {
	maxHeap* mh = createHeap(arr, end-start+1);
	while(mh->size > 1) {
		swap(mh->arr[0], mh->arr[mh->size - 1]);
		--mh->size;
		maxHeapify(mh, 0);
	}
}

int main(){
	int arr[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
	heapSort(arr, 0, sizeof(arr)/sizeof(arr[0])-1);
	printArray(arr, 0, sizeof(arr)/sizeof(arr[0])-1);
	return 0;
}