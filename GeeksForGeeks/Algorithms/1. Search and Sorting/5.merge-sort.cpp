// http://geeksquiz.com/merge-sort/
#include <iostream>
#include <climits>
#include <cstdio>
//#include <cmath>
//#include <vector>
//#include <string>
using namespace std;

void printArray(int a[], int start, int end) {
	for (int i=start; i<=end; i++) {
		cout<<a[i]<<" ";
	}
	cout<<'\n';
}

void merge(int a[], int start, int mid, int end) {
	int i=start, j=mid+1, k=0;
	int helper[end-start+1];
	while(i<=mid && j<=end) {
		if(a[i] < a[j]) {
			helper[k] = a[i];
			i++;
		}
		else {
			helper[k] = a[j];
			j++;
		}
		k++;
	}
	if(i>mid) {
		while(j<=end) {
			helper[k] = a[j];
			j++;
			k++;
		}
	}
	else {
		while(i<=mid) {
			helper[k] = a[i];
			i++;
			k++;
		}
	}
	for (int i = start, k=0; i <= end; ++i, ++k) {
		a[i] = helper[k];
	}
}

void mergeSort(int a[], int start, int end){
	if(end <= start)
		return;
	int ind = start + (end-start)/2;
	mergeSort(a, start, ind);
	mergeSort(a, ind+1, end);
	merge(a, start, ind, end);
}

int main(){
	int arr[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
	mergeSort(arr, 0, sizeof(arr)/sizeof(arr[0])-1);
	printArray(arr, 0, sizeof(arr)/sizeof(arr[0])-1);
	return 0;
}

/*
Time Complexity:Merge Sort is a recursive algorithm and time complexity can be expressed as following recurrence relation.
T(n) = 2T(n/2) + Theta(n)
The above recurrence can be solved either using Recurrence Tree method or Master method. It falls in case II of Master Method and solution of the recurrence is \Theta(nLogn).
Time complexity of Merge Sort is Theta(nLogn) in all 3 cases (worst, average and best) as merge sort always divides the array in two halves and take linear time to merge two halves.

Auxiliary Space: O(n)

Algorithmic Paradigm: Divide and Conquer

Sorting In Place: No in a typical implementation

Stable: Yes
*/