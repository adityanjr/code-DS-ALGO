// http://www.geeksforgeeks.org/check-for-majority-element-in-a-sorted-array

#include <iostream>
#include "array.h"

int _binarySearch(int *a, int start, int end, int x){
	if(start > end)
		return -1;
	int mid = (start+end)/2;
	if(a[mid] == x){
		int ind = _binarySearch(a, start, mid-1, x);
		if(ind == -1)
			return mid;
	}
	else if(a[mid] > x)
		return _binarySearch(a, start, mid-1, x);
	else
		return _binarySearch(a, mid+1, end, x);
}

bool isMajority(int *a, int n, int x){
	int ind = _binarySearch(a, 0, n-1, x);
	if(ind == -1)
		return false;
	if(a[ind+n/2] == x)
		return true;
	return false;

}

int main() {
   int arr[] = {1, 2, 3, 3, 3, 3, 3, 3, 4, 9, 10};
   int n = sizeof(arr)/sizeof(arr[0]);
   int x = 3;
   if(isMajority(arr, n, x))
     printf("%d appears more than %d times in arr[]", x, n/2);
   else
    printf("%d does not appear more than %d times in arr[]", x, n/2);
 
   return 0;
}
