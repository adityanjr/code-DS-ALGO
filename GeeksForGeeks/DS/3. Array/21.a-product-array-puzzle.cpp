// http://www.geeksforgeeks.org/a-product-array-puzzle/

#include <iostream>
#include "array.h"

void productArray(int *a, int n){
	int left[n], right[n], prod[n];
	left[0] = right[n-1] = 1;
	
	for(int i=1; i<n; i++)
		left[i] = a[i-1]*left[i-1];
	for(int i=n-2; i>=0; i--)
		right[i] = a[i+1]*right[i+1];
	for(int i=0; i<n; i++)
		prod[i] = left[i]*right[i];
	printArray(prod, n);
}

int main(){
  int arr[] = {10, 3, 5, 6, 2};
  int n = sizeof(arr)/sizeof(arr[0]);
  printf("The product array is: \n");
  productArray(arr, n);
  getchar();
}
