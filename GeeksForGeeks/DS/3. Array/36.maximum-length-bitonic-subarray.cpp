// http://www.geeksforgeeks.org/maximum-length-bitonic-subarray/

#include <iostream>
#include "array.h"

int bitonic(int *a, int n){
	if(n < 3)
		return n;
	int inc[n], dec[n];
	inc[0]=1;
	dec[n-1]=1;
	for(int i=0; i<n; i++){
		if(a[i-1] < a[i])
			inc[i] = inc[i-1]+1;
		else {
			inc[i] = 1;
		}
	}
	for(int i=n-2; i>=0; i--){
		if(a[i] > a[i+1]){
			dec[i] = dec[i+1]+1;
		}
		else {
			dec[i] = 1;
		}
	}
	int max=0;
	for(int i=0; i<n; i++){
		if(max < inc[i]+dec[i]-1)
			max = inc[i]+dec[i]-1;
	}
	return max;
}

int main(){
    int arr[] = {40, 30, 20, 10};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("\n Length of max length Bitnoic Subarray is %d", bitonic(arr, n));
    getchar();
    return 0;
}
