// http://www.geeksforgeeks.org/print-all-possible-combinations-of-r-elements-in-a-given-array-of-size-n
/*****/

#include <iostream>
#include "array.h"

void printUtil(int *a, int  n, int r, int curr, int *res, int count){
	if(count>r)
		return;
	else if(count == r){
		printArray(res, r);
	}
	for(int i=curr; i<n; i++){
		res[count] = a[i];
		printUtil(a, n, r, i+1, res, count+1);
	}
}

void printCombination(int *a, int n, int r){
	int curr = 0;
	int res[r];
	int count = 0;
	printUtil(a, n, r, curr, res, count);
}

int main(){
	int arr[] = {1, 2, 3, 4, 5};
    int r = 3;
    int n = sizeof(arr)/sizeof(arr[0]);
    printCombination(arr, n, r);
	return 0;
}

