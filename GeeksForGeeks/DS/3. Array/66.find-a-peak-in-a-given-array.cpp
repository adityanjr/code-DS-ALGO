// http://www.geeksforgeeks.org/find-a-peak-in-a-given-array/

#include <iostream>
#include "array.h"

int findPeak(int *a, int start, int end){
	int n = end-start+1;
	if(n==1){
		return start;
	}
	if(n==2){
		if(a[start]> a[end]){
			return start;
		}
		return end;
	}
	int mid = (end+start)/2;
	if(a[mid-1]<a[mid] && a[mid] > a[mid+1]){
		return mid;
	}
	else if(a[mid-1] > a[mid]) {
		return findPeak(a, start, mid-1);
	}
	else {
		return findPeak(a, mid+1, end);
	}
	
}

int main(){
	int arr[] = {10, 20, 15, 2, 23, 90, 67};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Index of a peak point is %d", findPeak(arr, 0, n-1));
	return 0;
}

