// http://www.geeksforgeeks.org/maximum-difference-between-two-elements/

#include <iostream>
#include "array.h"

int maxDiff(int *a, int n){
	int minNo = a[0];
	int maxDiff = 0;
	for(int i=1; i<n; i++){
		if(a[i] < minNo){
			minNo = a[i];
		}
		else{
			int diff = a[i] - minNo;
			if(diff > maxDiff)
				maxDiff = diff;
		}
	}
	return maxDiff;
}

int main(){
  int arr[] = {80, 2, 6, 1, 100};
  int size = sizeof(arr)/sizeof(arr[0]);
  printf("Maximum difference is %d",  maxDiff(arr, size));
  getchar();
  return 0;
}
