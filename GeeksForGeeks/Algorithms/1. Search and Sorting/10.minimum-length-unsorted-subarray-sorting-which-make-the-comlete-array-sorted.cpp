// http://www.geeksforgeeks.org/minimum-length-unsorted-subarray-sorting-which-makes-the-complete-array-sorted/
#include <iostream>
#include <climits>
#include <cstdio>
//#include <cmath>
//#include <vector>
//#include <string>
using namespace std;

void printArray(int a[], int start, int end) {
	for (int i=start; i<=end; i++) {
		cout<<a[i]<<" ";
	}
	cout<<'\n';
}

void func(int arr[], int n){
	int start=1, end=n-1;
	while(start<n && arr[start-1] <= arr[start])
		start++;
	while(end>=0 && arr[end] <= arr[end+1])
		end--;
	int min = arr[start], max = arr[end];
	for (int i = start; i <= end; ++i) {
		if(min > arr[i])
			min = arr[i];
		if(max < arr[i])
			max = arr[i];
	}
	int i=0;
	while(arr[i] <= min && i<start)
		i++;
	int j=n-1;
	while(arr[j] >= max && j>end)
		j--;
	if(j <= i)
		cout<<"none";
	else
		cout<<i<<" "<<j;
}

int main(){
//	int arr[] = {10, 12, 20, 30, 25, 40, 32, 31, 35, 50, 60};
	int arr[] = {0, 1, 30, 40, 50};
	func(arr, sizeof(arr)/sizeof(arr[0])-1);
	return 0;
}