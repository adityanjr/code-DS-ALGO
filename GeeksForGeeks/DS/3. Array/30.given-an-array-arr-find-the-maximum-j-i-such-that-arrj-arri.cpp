// http://www.geeksforgeeks.org/given-an-array-arr-find-the-maximum-j-i-such-that-arrj-arri
//***

#include <iostream>
#include "array.h"

int maxIndexDiff(int *a, int n){
	int Lmin[n], Rmax[n];
	int min = a[0];
	Lmin[0] = min;
	for(int i=1; i<n; i++){
		if(min > a[i])
			min = a[i];
		Lmin[i] = min;
	}
	int ma = a[n-1];
	Rmax[n-1] = ma;
	for(int i=n-2; i>=0; i--){
		if(ma < a[i])
			ma = a[i];
		Rmax[i] = ma;
	}
	int i=0, j=0;
	ma=-1;
	while(i<n && j<n){
		if(Lmin[i] < Rmax[j]){
			ma = max(ma, j-i);
			j++;
		}
		else {
			i++;
		}
	}
	return ma;
}

int main(){
    int arr[] = {9, 2, 3, 4, 5, 6, 7, 8, 18, 0};
    int n = sizeof(arr)/sizeof(arr[0]);
    int maxDiff = maxIndexDiff(arr, n);
    printf("\n %d", maxDiff);
    getchar();
    return 0;
}
