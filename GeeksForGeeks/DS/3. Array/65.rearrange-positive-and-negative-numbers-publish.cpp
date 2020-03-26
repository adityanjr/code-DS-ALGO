// http://www.geeksforgeeks.org/rearrange-positive-and-negative-numbers-publish

#include <iostream>
#include "array.h"

void rearrange(int *a, int n){
	int j=-1;
	bool pos = true;
	int i=0;
	while(i<n){
		if(i==j){
			i++;
		}
		if(pos && a[i] > 0){
			pos = !pos;
			j++;
			swap(&a[j], &a[i]);
		}
		else if(!pos && a[i] < 0){
			pos = !pos;
			j++;
			swap(&a[j], &a[i]);
		}
		else
			i++;
	}
	cout<<i<<" "<<j<<'\n';
}

int main(){
	int arr[] = {-1, 2, -3, 4, 5, 6, -7, -8, -9};
    int n = sizeof(arr)/sizeof(arr[0]);
    rearrange(arr, n);
    printArray(arr, n);
	return 0;
}

