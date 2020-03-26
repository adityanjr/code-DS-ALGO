// http://www.geeksforgeeks.org/count-number-of-occurrences-in-a-sorted-array

#include <iostream>
#include "array.h"

int binaryLast(int *a, int start, int end, int x){
	if(start > end)
		return -1;
	int mid = (start+end)/2;
	if(a[mid] == x){
		int idx = binaryLast(a, mid+1, end, x);
		if(idx == -1)
			return mid;
		else
			return idx;
	}
	else if(a[mid] > x){
		return binaryLast(a, start, mid-1, x);
	
	}
	else
		return binaryLast(a, mid+1, end, x);
}


int binaryFirst(int *a, int start, int end, int x){
	if(start > end)
		return -1;
	int mid = (start+end)/2;
	if(a[mid] == x){
		int idx = binaryFirst(a, start, mid-1, x);
		if(idx == -1)
			return mid;
		else
			return idx;
	}
	else if(a[mid] > x){
		return binaryFirst(a, start, mid-1, x);
	
	}
	else
		return binaryFirst(a, mid+1, end, x);
}

int count(int *a, int x, int n){
	int i = binaryFirst(a, 0, n-1, x);
	int j = binaryLast(a, i, n-1, x);
	return j-i+1;
}

int main(){
  int arr[] = {1, 2, 2, 3, 3, 3, 3, 4};
  int x =  3;  // Element to be counted in arr[]
  int n = sizeof(arr)/sizeof(arr[0]);
  int c = count(arr, x, n);
  cout<<x<<" occurs "<<c<<" times ";
  return 0;
}
