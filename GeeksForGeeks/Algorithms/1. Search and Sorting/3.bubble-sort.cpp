// http://geeksquiz.com/bubble-sort/
#include <iostream>
#include <climits>
#include <cstdio>
using namespace std;

void swap(int &a, int &b) {
	int tmp = a;
	a = b;
	b = tmp;
}

void printArray(int a[], int start, int end) {
	for (int i=start; i<=end; i++) {
		cout<<a[i]<<" ";
	}
	cout<<'\n';
}

void bubbleSort(int a[], int start, int end){
	for (int i = start; i < end; ++i) {
		for (int j = start; j < end; ++j) {
			if(a[j] > a[j+1])
				swap(a[j], a[j+1]);
		}
	}
}

int main(){
	int arr[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
	bubbleSort(arr, 0, sizeof(arr)/sizeof(arr[0])-1);
	printArray(arr, 0, sizeof(arr)/sizeof(arr[0])-1);
	return 0;
}

/*
Time Complexity: O(n*n)

Auxiliary Space: O(1)

Boundary Cases: Bubble sort takes minimum time (Order of n) when elements are already sorted.

Sorting In Place: Yes

Stable: Yes

Due to its simplicity, bubble sort is often used to introduce the concept of a sorting algorithm.
In computer graphics it is popular for its capability to detect a very small error (like swap of just two elements) in almost-sorted arrays and fix it with just linear complexity (2n). For example, it is used in a polygon filling algorithm, where bounding lines are sorted by their x coordinate at a specific scan line (a line parallel to x axis) and with incrementing y their order changes (two elements are swapped) only at intersections of two lines (Source: Wikipedia)
*/