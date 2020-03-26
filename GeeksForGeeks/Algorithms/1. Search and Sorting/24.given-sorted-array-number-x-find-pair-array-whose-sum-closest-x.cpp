// http://geeksquiz.com/given-sorted-array-number-x-find-pair-array-whose-sum-closest-x/

#include <iostream>
#include <climits>
#include <cstdio>
//#include <cmath>
//#include <vector>
//#include <string>
using namespace std;

int func(int *arr, int start, int end){
	if(start>end)
		return 0;
	int mid = start + (end-start)/2;
	if (arr[mid] == 0)
		return func(arr, start, mid-1);
	else
		return mid-start+1+func(arr, mid+1, end);
}

int main(){
	int arr[] = {1, 1, 1, 1, 1, 1, 0};
	cout<<func(arr, 0, sizeof(arr)/sizeof(*arr)-1);
	return 0;
} 