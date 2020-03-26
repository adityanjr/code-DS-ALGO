// http://geeksquiz.com/selection-sort/
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

void selectionSort(int a[], int start, int end){
	for (int i = start; i <= end; ++i) {
		int min = i;
		for (int j = i; j <= end; j++) {
			if(a[min] > a[j])
				min = j;
		}
		swap(a[i], a[min]);
	}
}

int main(){
	int arr[] = {56, 2, 6, 10, 0, 0, 1, 23, 54 , 1};
	selectionSort(arr, 0, sizeof(arr)/sizeof(arr[0])-1);
	printArray(arr, 0, sizeof(arr)/sizeof(arr[0])-1);
	return 0;
}

/*
Time Complexity: O(n*n) as there are two nested loops.

Auxiliary Space: O(1)

The good thing about selection sort is it never makes more than O(n) swaps and can be useful when memory write is a costly operation.
*/