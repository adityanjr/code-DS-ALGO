// http://www.geeksforgeeks.org/find-a-sorted-subsequence-of-size-3-in-linear-time/

#include <iostream>
#include "array.h"

void find3Numbers(int *a, int n){
	int lmin[n], rmax[n];
	lmin[0] = -1;
	rmax[n-1] = -1;
	int tmp = 0;
	for(int i=1; i<n; i++){
		if(a[tmp] < a[i]){
			lmin[i] = tmp;
		}
		else{
			lmin[i] = -1;
		}
		if(a[tmp] > a[i])
			tmp = i;
	}
	tmp = n-1;
	for(int i=n-2; i>=0; i--){
		if(a[tmp] > a[i]){
			rmax[i] = tmp;
		}
		else{
			rmax[i] = -1;
		}
		if(a[tmp] < a[i])
			tmp = i;
	}
	for(int i=0; i<n; i++){
		if(lmin[i] > -1 && rmax[i] > -1){
			cout<<a[lmin[i]]<<" "<<a[i]<<" "<<a[rmax[i]]<<'\n';
		}
	}
}

int main(){
    int arr[] = {1, 2, 3, 4};
    int n = sizeof(arr)/sizeof(arr[0]);
    find3Numbers(arr, n);
    return 0;
}
