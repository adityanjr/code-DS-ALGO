// http://www.geeksforgeeks.org/minimum-length-unsorted-subarray-sorting-which-makes-the-complete-array-sorted/

#include <iostream>
#include "array.h"

void printUnsorted(int *a, int n){
	int s=-1, e=n;
	for(int i=1; i<n; i++){
		if(a[i-1] > a[i]){
			s = i-1;
			break;
		}
	}
	for(int i=n-1; i>=0; i--){
		if(a[i-1] > a[i]){
			e = i;
			break;
		}
	}
	cout<<s<<" "<<e<<'\n';
	int min=INT_MAX, max = INT_MIN;
	for(int i=s; i<=e; i++){
		if(min > a[i])
			min = a[i];
		if(max < a[i])
			max = a[i];
	}
	for(int i=0; i<s; i++){
		if(a[i]>min)
			s = i;
	}
	for(int i=e+1; i<n; i++){
		if(a[i] < max)
			e = i;
	}
	cout<<s<<" "<<e;
}

int main(){
  int arr[] = {10, 12, 20, 30, 25, 40, 32, 31, 35, 50, 60};
  int arr_size = sizeof(arr)/sizeof(arr[0]);
  printUnsorted(arr, arr_size);
  getchar();
  return 0;
}
