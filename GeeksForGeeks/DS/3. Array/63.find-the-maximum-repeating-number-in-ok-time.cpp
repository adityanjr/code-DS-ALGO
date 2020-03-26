// http://www.geeksforgeeks.org/find-the-maximum-repeating-number-in-ok-time

#include <iostream>
#include "array.h"

int maxRepeating(int *a, int n, int k){
	for(int i=0; i<n; i++){
		int idx = a[i]%k;
		a[idx] = a[idx]+k; 
	}
	int max = 0;
	int idx = -1;
	for(int i=0; i<n; i++){
		if(max < a[i]){
			max = a[i];
			idx = i;
		}
	}
	return idx;
}

int main(){
	int arr[] = {1, 2, 2, 2, 0, 2, 0, 2, 3, 8, 0, 9, 2, 3};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 8;
    cout << "The maximum repeating number is "<<maxRepeating(arr, n, k) << endl;
	return 0;
}

