// http://www.geeksforgeeks.org/find-the-smallest-positive-number-missing-from-an-unsorted-array

#include <iostream>
#include <algorithm>
#include "array.h"

int findMissing(int *a, int n){
	
	//Segregate positive
	int j=-1;
	for(int i=0; i<n; i++){
		if(a[i]>0){
			j++;
			swap(&a[i], &a[j]);
		}
	}
	for(int i=0; i<j; i++){
		if(abs(a[i]) <= j){
			a[abs(a[i])] = -a[abs(a[i])];
		}
	}
	for(int i=1; i<j; i++){
		if(a[i]>0)
			return i;
	}
}

int main(){
  int arr[] = {0, 10, 2, -10, -20};
  int arr_size = sizeof(arr)/sizeof(arr[0]);
  int missing = findMissing(arr, arr_size);
  printf("The smallest positive missing number is %d ", missing);
  getchar();
  return 0;
}
