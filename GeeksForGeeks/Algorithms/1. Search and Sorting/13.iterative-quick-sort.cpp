// http://www.geeksforgeeks.org/iterative-quick-sort/
#include <iostream>
#include <stack>
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

int partition(int *arr, int start, int end) {
	int piv = arr[end];
	int j = start-1;
	for (int i = start; i < end; ++i) {
		if(arr[i] <= piv){
			j++;
			swap(&arr[j], &arr[i]);
		}
	}
	swap(&arr[j+1], &arr[end]);
	return (j+1);
}

void iterativeQuickSort(int *arr, int n){
	stack<int> v;
	v.push(0);		//start
	v.push(n-1);	//end
	while(!v.empty()) {
		int end = v.top();
		v.pop();
		int start = v.top();
		v.pop();
		int piv = partition(arr, start, end);
		if(piv-1 > start) {
			v.push(start);
			v.push(piv-1);
		}
		if(piv+1 < end) {
			v.push(piv+1);
			v.push(end);
		}
	}
}

int main(){
	int arr[] = {4, 3, 5, 2, 1, 3, 2, 3};
	int n = sizeof(arr)/sizeof(*arr);
	iterativeQuickSort(arr, n);
	printArray(arr, 0, n-1);
	return 0;
}