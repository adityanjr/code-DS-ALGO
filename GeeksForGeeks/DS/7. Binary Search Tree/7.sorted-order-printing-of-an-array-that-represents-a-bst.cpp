// http://www.geeksforgeeks.org/sorted-order-printing-of-an-array-that-represents-a-bst

#include <iostream>
#include <climits>
#include <cstdio>
using namespace std;

void printSorted(int *arr, int start, int end){
	if(start > end)
		return;
	printSorted(arr, 2*start+1, end);
	cout<<arr[start]<<" ";
	printSorted(arr, 2*start+2, end);
}

int main(){
	int arr[] = {4, 2, 5, 1, 3};
  	int arr_size = sizeof(arr)/sizeof(int);
  	printSorted(arr, 0, arr_size-1);
	return 0;
}