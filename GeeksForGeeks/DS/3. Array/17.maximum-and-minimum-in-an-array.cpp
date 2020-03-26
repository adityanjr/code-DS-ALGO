// http://www.geeksforgeeks.org/maximum-and-minimum-in-an-array/

#include <iostream>
#include "array.h"

struct _pair {
	int min;
	int max;
};

struct _pair getMinMax(int *a, int start, int end){
	int n=end-start+1;
	if(n==1){
		return {a[start], a[start]};
	 }
	else if( n==2){
		return {min(a[start], a[end]), max(a[start], a[end])};
	}
	else {
		int mid = (start+end)/2;
		_pair tmp1 = getMinMax(a, start, mid);
		_pair tmp2 = getMinMax(a, mid+1, end);
		return {min(tmp1.min, tmp2.min), max(tmp1.max, tmp2.max)};
	}
}

int main(){
  int arr[] = {1000, 11, 445, 1, 330, 3000};
  int arr_size = 6;
  _pair minmax = getMinMax(arr, 0, arr_size-1);
  printf("\nMinimum element is %d", minmax.min);
  printf("\nMaximum element is %d", minmax.max);
}
