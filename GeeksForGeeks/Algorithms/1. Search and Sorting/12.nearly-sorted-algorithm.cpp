// http://www.geeksforgeeks.org/nearly-sorted-algorithm/

#include <iostream>
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

struct heap {
	int size;
	int *arr;
};

void minHeapify(heap *Heap, int ind){
	int min = ind;
	int lChild = (ind<<1)+1;
	int rChild = (ind<<1)+2;

	if(lChild < Heap->size && Heap->arr[lChild] < Heap->arr[ind])
		min = lChild;
	if(rChild < Heap->size && Heap->arr[rChild] < Heap->arr[ind])
		min = rChild;
	if(min != ind) {
		swap(&Heap->arr[ind], &Heap->arr[min]);
		minHeapify(Heap, min);
	}
}

struct heap* createMinHeap(int *arr, int size){
	heap* Heap = new heap;
	Heap->arr = arr;
	Heap->size = size;
	for (int i = (size-2)/2; i >= 0; --i) {
		minHeapify(Heap, i);
	}
	return Heap;
}

void heapSortWithKElements(int *a, int size, int k) {
	int help[k+1];
	for(int i=0; i <= k; i++)
		help[i] = a[i];
	heap* Heap = createMinHeap(help, k+1);
	int j=0;
	for (int i = k+1; i < size; ++i, ++j) {
		a[j] = Heap->arr[0];
		Heap->arr[0] = a[i];
		minHeapify(Heap, 0);
	}
	for (; j < size; ++j) {
		a[j] = Heap->arr[0];
		Heap->arr[0] = Heap->arr[(Heap->size)-1];
		Heap->size -=1;
		minHeapify(Heap, 0);
	}
}

int main(){
	int arr[] = {2, 6, 3, 12, 56, 8};
	int k = 3;
	heapSortWithKElements(arr, sizeof(arr)/sizeof(arr[0]), k);
	printArray(arr, 0, sizeof(arr)/sizeof(arr[0])-1);
	return 0;
}