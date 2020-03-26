// http://www.geeksforgeeks.org/find-k-closest-elements-given-value

#include <iostream>
#include <cstdio>
using namespace std;

int binarySearch(int arr[], int start, int end, int x){
	if(start>end)
		return -1;
	int mid = (start+end)/2;
	if (arr[mid] == x)
		return mid;
	if (arr[mid] > x)
		return binarySearch(arr, start, mid-1, x);
	binarySearch(arr, mid+1, end, x);
}

void func(int arr[], int n, int k, int x){
	int index = binarySearch(arr, 0, n-1, x);
	int i = (index-4 >= 0 ? index-4:0);
	int j = (index+4 <= n-1 ? index+4:n-1);
	while(j-i > k) {
		if(arr[index] - arr[i] > arr[j] - arr[index])
			i++;
		else
			j--;
	}
	for(; i<=j; i++){
		if(index != i)
			cout<<arr[i]<<" ";
	}
}

int main(){
	int arr[] = {12, 16, 22, 30, 35, 39, 42, 45, 48, 50, 53, 55, 56};
	func(arr, sizeof(arr)/sizeof(*arr), 5, 35);
	return 0;
}