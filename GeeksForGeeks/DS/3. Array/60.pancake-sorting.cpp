// http://www.geeksforgeeks.org/pancake-sorting

#include <iostream>
#include "array.h"

void pancakeSort(int *a, int n){
	int m;
	for(int i=n-1; i>=0; i--){
		m = i;
		for(int j=i-1; j>=0; j--){
			if(a[m] < a[j]){
				m = j;
			}
		}
		reverse(a, m, i);
	}
}

int main(){
	int arr[] = {23, 10, 20, 11, 12, 6, 7};
    int n = sizeof(arr)/sizeof(arr[0]);
 
    pancakeSort(arr, n);
 	
    printArray(arr, n);
	return 0;
}

