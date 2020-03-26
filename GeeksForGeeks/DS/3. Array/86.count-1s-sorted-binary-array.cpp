// http://geeksquiz.com/count-1s-sorted-binary-array/

#include <iostream>
#include "array.h"

int countOnes(bool *a, int start, int end){
	if(start >end)
		return 0;
	int mid = (start+end)/2;
	if(a[mid] == 1){
		return mid-start+1+countOnes(a, mid+1, end);
	}
	else {
		return countOnes(a, start, mid-1);
	}
}

int main(){
	bool arr[] = {1, 1, 1, 0, 0, 0};
   int n = sizeof(arr)/sizeof(arr[0]);
   cout << "Count of 1's in given array is " << countOnes(arr, 0, n-1);
	return 0;
}