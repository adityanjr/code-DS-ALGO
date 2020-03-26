// Heap Header File

#include <iostream>
#include <cstdio>
#include <climits>
using namespace std;

struct heap {
	int *arr;
	int size;
	int capacity;
};

heap *createHeap(int cap){
	heap *h = new heap;
	h->arr = new int[cap];
	h->capacity = cap;
	h->size = 0;
	return h;
}

void heapify(heap *h, int idx){
	if(idx < 0)
		return;
	int smallest = idx;
	int left = 2*idx+1;
	int right = 2*idx+2;
	int size = h->size;
	if(left < size && h->arr[left] < h->arr[idx]){
		smallest = left;
	}
	if(right < size && h->arr[right] < h->arr[smallest]){
		smallest = right;
	}
	if(smallest != idx){
		swap(h->arr[smallest], h->arr[idx]);
		heapify(h, smallest);
	}
}

void insertKey(heap *h, int key){
	if(h->size >= h->capacity)
		return;
	h->arr[h->size] = key;
	(h->size)++;
	for(int i=(h->size/2)-1; i>=0; i--){
		heapify(h, i);
	}
	return;

}

int extractMin(heap *h){
	int res = h->arr[0];
	swap(h->arr[0], h->arr[h->size-1]);
	h->size--;
	heapify(h, 0);
	return res;
}

int getMin(heap *h){
	return h->arr[0];
}

void decreaseKey(heap *h, int i, int val){
	h->arr[i] = val;
	while(i != 0 && h->arr[((i+1)/2)-1] > h->arr[i]){
		swap(h->arr[((i+1)/2)-1], h->arr[i]);
		i = ((i+1)/2)-1;
	}
}

void deleteKey(heap *h, int key){
	decreaseKey(h, key, INT_MIN);
	extractMin(h);
}
