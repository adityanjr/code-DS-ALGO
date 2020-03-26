// http://www.geeksforgeeks.org/greedy-algorithms-set-3-huffman-coding/

#include <iostream>
#include <climits>
#include <cstdio>
using namespace std;

struct node {
	char data;
	int freq;
	node *left, *right;
};

struct Heap {
	unsigned size;
	unsigned capacity;
	node **array;
};

node* newNode(char data, unsigned freq) {
	node *tmp = new node;
	tmp->data = data;
	tmp->freq = freq;
	tmp->left = NULL;
	tmp->right = NULL;
	return tmp;
}

Heap* createMinHeap(unsigned capacity) {
	Heap* heap = new Heap;
	heap->size = 0;
	heap->capacity = capacity;
	node* arr[capacity];
	heap->array = arr;
	return heap;
}

void swapNode(node *a, node *b) {
	node* t = a;
	*a = *b;
	*b = *t;
}

void Heapify(Heap* heap, int ind) {
	int min = ind;
	int left = 2*ind+1;
	int right = 2*ind+2;

	if(left < heap->size && heap->array[left]->freq < heap->array[ind]->freq)
		min = left;
	if(right < heap->size && heap->array[right]->freq < heap->array[ind]->freq)
		min = right;
	if(min != ind) {
		swapNode(heap->array[ind], heap->array[min]);
		Heapify(heap, min);
	}
}

node* extractMin(Heap *heap) {
	node* min = heap->array[0];
	heap->array[0] = heap->array[heap->size-1];
	heap->size--;
	Heapify(heap, 0);
	return min;
}

void insertHeap(Heap *heap, struct node* n) {
	heap->size++;
	int i = heap->size-1;
	while(i && n->freq < heap->array[(i-1)/2]->freq) {
		heap->array[i] = heap->array[(i-1)/2];
		i = (i-1)/2;
	}
	heap->array[i] = n;
}

void buildHeap(Heap *heap) {
	int n = heap->size - 1;
	int i;
	for (int i = (n-1)/2; i >=0;  --i) {
		Heapify(heap, i);
	}
}

void printArr(int arr[], int n) {
	for (int i = 0; i < n; ++i){
		cout<<arr[i]<<" ";
	}
	cout<<'\n';
}

bool isLeaf(node* root) {
	return !(root->left) && !(root->right);
}

node* buildHuffmanTree(char data[], int freq[], int size) {
	node *top, *left, *right;
	Heap *heap = createMinHeap(size);
	for (int i = 0; i < size; ++i){
		heap->array[i] = newNode(data[i], freq[i]);
	}
	heap->size = size;
	buildHeap(heap);

	while(heap->size != 1) {
		left = extractMin(heap);
		right = extractMin(heap);
		top = newNode('$', left->freq+right->freq);
		top->left = left;
		top->right = right;
		insertHeap(heap, top);
	}
	return extractMin(heap);
}

void printCodes(node* root, int arr[], int top){
	if(root->left) {
		arr[top] = 0;
		printCodes(root->left, arr, top+1);
	}
	if(root->right) {
		arr[top] = 1;
		printCodes(root->right, arr, top+1);
	}

	if(isLeaf(root)) {
		cout<<root->data<<": ";
		printArr(arr, top);
	}
}

void HuffmanCodes(char data[], int freq[], int size) {
   //  Construct Huffman Tree
	node* root = buildHuffmanTree(data, freq, size);
 
   // Print Huffman codes using the Huffman tree built above
   int arr[100], top = 0;
   printCodes(root, arr, top);
}

int main(){
	char arr[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = {5, 9, 12, 13, 16, 45};
    int size = sizeof(arr)/sizeof(arr[0]);
    HuffmanCodes(arr, freq, size);
	return 0;
}