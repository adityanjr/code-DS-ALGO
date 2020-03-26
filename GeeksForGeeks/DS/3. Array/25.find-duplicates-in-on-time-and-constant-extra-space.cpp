// http://www.geeksforgeeks.org/find-duplicates-in-on-time-and-constant-extra-space

#include <iostream>
#include <cmath>
#include "array.h"

void printRepeating(int *a, int n){
	for(int i=0; i<n; i++){
		int idx = abs(a[i]);
		if(a[idx] < 0){
			cout<<abs(a[i])<<" ";
		}
		else {
			a[idx] = -a[idx];
		}
	}
}

int main(){
  int arr[] = {1, 2, 3, 1, 3, 6, 6};
  int arr_size = sizeof(arr)/sizeof(arr[0]);
  printRepeating(arr, arr_size);
  return 0;
}
