// http://www.geeksforgeeks.org/maximum-sum-such-that-no-two-elements-are-adjacent/
//***

#include <iostream>
#include "array.h"

int FindMaxSum(int *a, int n){
	int inc = a[0];
	int exc = 0;
	int excNew;
	for(int i=1; i<n; i++){
		excNew = max(exc, inc);
		inc = exc + a[i];
		exc = excNew;
	}
	return max(inc, exc);
}

/* Driver program to test above function */
int main(){
  int arr[] = {5, 5, 10, 100, 10, 5};
  printf("%d \n", FindMaxSum(arr, 6));
  return 0;
}
