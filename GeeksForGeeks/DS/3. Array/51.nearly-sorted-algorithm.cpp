// http://www.geeksforgeeks.org/nearly-sorted-algorithm/

#include<iostream>
#include <algorithm>
#include "array.h"

bool compare(int a, int b){
	return (a>b);
}

void sortK(int *a, int n, int k){
	make_heap(a, a+3, compare);
	for(int i=1; i<n-2; i++){
		make_heap(a+i, a+i+3, compare);
	}
	k--;
	while(k>0){
		make_heap(a+n-k, a+n, compare);
		k--;
	}
}

int main(){
	int k = 3;
    int arr[] = {2, 6, 3, 12, 56, 8};
    int n = sizeof(arr)/sizeof(arr[0]);
    sortK(arr, n, k);
    cout << "Following is sorted array\n";
    printArray (arr, n);
	return 0;
}

