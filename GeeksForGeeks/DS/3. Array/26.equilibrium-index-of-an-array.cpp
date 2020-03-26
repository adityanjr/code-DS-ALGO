// http://www.geeksforgeeks.org/equilibrium-index-of-an-array/

#include <iostream>
#include "array.h"

int equilibrium(int *a, int n){
	int sum=0;
	for(int i=0; i<n; i++)
		sum += a[i];
	int leftSum=0;
	for(int i=0; i<n; i++){
		sum -= a[i];
		if(sum == leftSum)
			return i;
		else {
			leftSum += a[i];
		}
	}
	return -1;
}

int main(){
  int arr[] = {-7, 1, 5, 2, -4, 3, 0};
  int arr_size = sizeof(arr)/sizeof(arr[0]);
  printf("First equilibrium index is %d\n", equilibrium(arr, arr_size));
 
  getchar();
  return 0;
}
