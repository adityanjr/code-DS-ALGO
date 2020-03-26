// http://www.geeksforgeeks.org/k-largestor-smallest-elements-in-an-array/

#include <iostream>
#include "array.h"

struct Heap {
	int size;
	int *arr;
};

//min
void Heapify(Heap *heap, int idx){
	int smallest = idx;
	int left = (idx<<1)+1;
	int right = (idx<<1) + 2;
	if(left < heap->size && heap->arr[left] < heap->arr[smallest]){
		smallest = left;
	}
	if(right < heap->size && heap->arr[right] < heap->arr[smallest]){
		smallest = right;
	}
	
	if(smallest != idx){
		swap(&heap->arr[smallest], &heap->arr[idx]);
		Heapify(heap, smallest);
	}
}

int extractMin(Heap *heap){
	int tmp = heap->arr[0];
	heap->arr[0] = heap->arr[heap->size-1];
	heap->size--;
	Heapify(heap, 0);
}

void insert(Heap *heap, int data){
	heap->arr[heap->size] = data;
	heap->size++;
	Heapify(heap, (heap->size-2)/2);
}

int kthMinElement(int *a, int n, int k){
	Heap *heap = new Heap;
	heap->size = k;
	int ar[k];
	for(int i=0; i<k; i++){
		ar[i] = a[i];
	}
	heap->arr = ar;
	Heapify(heap, 0);
	for(int i=(heap->size-2); i>=0; i--){
		Heapify(heap, i);
	}
	for(int i=k; i<n; i++){
		if(a[i] > heap->arr[0]){
			extractMin(heap);
			insert(heap, a[i]);
		}
	}
	return heap->arr[0];
}

int main(){
	int arr[] = {4, 1, 62, 9, 3, 5};
	int k = 4;
	cout<<kthMinElement(arr, sizeof(arr)/sizeof(int), k);
	return 0;
}
