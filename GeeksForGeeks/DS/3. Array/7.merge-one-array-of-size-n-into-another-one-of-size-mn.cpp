// http://www.geeksforgeeks.org/merge-one-array-of-size-n-into-another-one-of-size-mn

#include <iostream>
#include "array.h"

#define NA -1

void moveToEnd(int *a, int N){
	int k = N-1;
	for(int i=N-1; i>=0; i--) {
		if(a[i] != NA) {
			swap(&a[i], &a[k]);
			k--;
		}
	}
}

void merge(int *a, int *b, int n, int m){
	moveToEnd(a, m+n);
	int i = m;
	int j = 0;
	int k = 0;
	while(k < n+m) {
		if(a[i] < b[j]) {
			swap(&a[i], &a[k]);
			k++;
			i++;
		}
		else {
			a[k] = b[j];
			k++;
			j++;
		}
	}
}

int main(){
	int mPlusN[] = {2, 8, NA, NA, NA, 13, NA, 15, 20};
 	int N[] = {5, 7, 9, 25};
 	int n = sizeof(N)/sizeof(N[0]);
 	int m = sizeof(mPlusN)/sizeof(mPlusN[0]) - n;
 
  	/*Merge N[] into mPlusN[] */
  	merge(mPlusN, N, m, n);
 
  	/* Print the resultant mPlusN */
  	printArray(mPlusN, m+n);
	return 0;
}