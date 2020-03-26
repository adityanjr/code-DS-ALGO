// http://www.geeksforgeeks.org/segment-tree-set-1-sum-of-given-range/
/*Incomplete*/

#include <iostream>
#include <cmath>
#include "bt.h"

int *constructST(int *arr, int n){
	int x = ceil(log2(n));
	int max_size = 2*pow(2, x) - 1;
	int *res = new int[max_size];
	int size = max_size - 2*(pow(2, x)-n);
	int i= size-1;
	for(int j=n-1; j>=0; j--){
		res[i] = arr[j];
		i--;
	}
	int j = size-1;
	if(n%2 == 0){
		res[i] = res[j] + res[j-1];
		i--;
		j -= 2;
	}
	else {
		res[i] = res[j];
		i--;
		j--;
	}
	while(i>=0 && j>=0){
		res[i] = res[j] + res[j-1];
		i--;
		j -= 2;
	}

	printArray(res, size);
	return res;
}

int getSum(int *arr, int n, int start, int end){
	
}

int main(){
	 int arr[] = {1, 3, 5, 7, 9, 11};
    int n = sizeof(arr)/sizeof(arr[0]);

    // Build segment tree from given array
    int *st = constructST(arr, n);

    // Print sum of values in array from index 1 to 3
    //printf("Sum of values in given range = %d\n", getSum(st, n, 1, 3));

    // Update: set arr[1] = 10 and update corresponding segment
    // tree nodes
//    updateValue(arr, st, n, 1, 10);

    // Find sum after the value is updated
  //  printf("Updated sum of values in given range = %d\n", getSum(st, n, 1, 3));
	return 0;
}

