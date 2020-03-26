// http://www.geeksforgeeks.org/find-the-maximum-element-in-an-array-which-is-first-increasing-and-then-decreasing/

#include <iostream>
#include "array.h"

int findMaximum(int *a, int start, int end){
	if(start>end){
		return -1;
	}
	int n=end-start+1;
	if(n==1)
		return a[start];
	if(n==2){
		if(a[start] > a[end])
			return a[start];
		return a[end];
	}
	int mid = (start+end)/2;
	if(a[mid-1] < a[mid] && a[mid] > a[mid+1])
		return a[mid];
	else if(a[mid-1] < a[mid])
		return findMaximum(a, mid+1, end);
	return findMaximum(a, start, mid-1);
}

int main(){
   int arr[] = {1, 30, 40, 50, 60, 70, 23, 20};
   int n = sizeof(arr)/sizeof(arr[0]);
   printf("The maximum element is %d", findMaximum(arr, 0, n-1));
   getchar();
   return 0;
}
