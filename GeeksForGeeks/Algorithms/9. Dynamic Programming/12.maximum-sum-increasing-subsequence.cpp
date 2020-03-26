// http://www.geeksforgeeks.org/dynamic-programming-set-14-maximum-sum-increasing-subsequence/

#include <iostream>
#include <cstdio>
using namespace std;

int maxSumIS(int *arr, int n) {
	int cache[n];
	for(int i=0; i<n; i++){
		cache[i] = arr[i];
	}
	for(int i=1; i<n; i++){
		int tmp = cache[i];
		for(int j=0; j<i; j++){
			if(arr[j] < arr[i])
				tmp = max(tmp, cache[j]+cache[i]);
		}
		cache[i] = tmp;
	}
	int M = cache[0];
	for(int i=1; i<n; i++)
		M = max(M, cache[i]);
	return M;
}

int main(){
	int arr[] = {1, 101, 2, 3, 100, 4, 5};
  int n = sizeof(arr)/sizeof(arr[0]);
  printf("Sum of maximum sum increasing subsequence is %d\n", maxSumIS( arr, n ) );
	return 0;
}

