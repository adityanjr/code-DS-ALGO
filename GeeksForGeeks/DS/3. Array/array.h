#include <iostream>
using namespace std;

void swap(int *a, int *b){
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void printArray(int *a, int n){
	for(int i=0; i<n; i++)
	    cout<<a[i]<<" ";
	cout<<'\n';
}

int binarySearch(int *a, int start, int end, int x){
	if(start>end)
 	    return -1;
	int mid = (end+start)/2;
	if(a[mid] == x)
 	    return mid;
	else if(a[mid] > x)
		 return binarySearch(a, start, mid-1, x);
    return binarySearch(a, mid+1, end, x);
}

void reverse(int *a, int start, int end){
	if(start >= end)
		return;
	swap(&a[start], &a[end]);
	reverse(a, start+1, end-1);
}
