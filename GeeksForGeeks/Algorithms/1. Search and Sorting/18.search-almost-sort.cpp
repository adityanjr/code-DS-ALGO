// http://www.geeksforgeeks.org/search-almost-sorted-array/

#include <iostream>
#include <climits>
#include <cstdio>
//#include <cmath>
//#include <vector>
//#include <string>
using namespace std;

int modBinarySearch(int arr[], int start, int end, int x){
	if(start > end)
		return -1;
	int mid = start + (end-start)/2;
	if(arr[mid] == x)
		return mid;
	else if (mid>0 && arr[mid-1] == x)
		return mid-1;
	else if (mid<end && arr[mid+1] == x)
		return mid+1;
	else if(arr[mid] < x)
		return modBinarySearch(arr, mid+2, end, x);
	return modBinarySearch(arr, start, mid-2, x);
}

int main(){
	int arr[] =  {10, 3, 40, 20, 50, 80, 70};
	cout<<modBinarySearch(arr, 0, sizeof(arr)/sizeof(*arr), 70);
	return 0;
}