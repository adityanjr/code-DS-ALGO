// http://www.geeksforgeeks.org/find-two-non-repeating-elements-in-an-array-of-repeating-elements

#include <bits/stdc++.h>
#include "bit.h"
using namespace std;

void get2NonRepeatingNos(int *arr, int n, int *x, int *y){
	int _xor = 0;
	for(int i=0; i<n; i++){
		_xor ^= arr[i];
	}
	int setbit = _xor & ~(_xor-1);

	int a=0, b=0;
	for(int i=0; i<n; i++){
		if(arr[i]&setbit)
			a ^= arr[i];
		else
			b ^= arr[i];
	}
	*x = a;
	*y = b;
}

int main(){
	int arr[] = {2, 3, 7, 9, 11, 2, 3, 11};
  	int *x = (int *)malloc(sizeof(int));
  	int *y = (int *)malloc(sizeof(int));
  	get2NonRepeatingNos(arr, 8, x, y);
  	printf("The non-repeating elements are %d and %d", *x, *y);
	return 0;
}

