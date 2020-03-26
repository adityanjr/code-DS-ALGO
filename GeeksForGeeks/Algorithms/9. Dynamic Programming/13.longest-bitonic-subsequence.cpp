// http://www.geeksforgeeks.org/dynamic-programming-set-15-longest-bitonic-subsequence

#include <iostream>
#include <cstdio>
using namespace std;

int *Lis(int *arr, int n){
	int *cache = new int[n];
	for(int i=0; i<n; i++)
		cache[i] = 1;
	for(int i=1; i<n; i++){
		int tmp = cache[i];
		for(int j=0; j<i; j++){
			if(arr[j] < arr[i])
				tmp = max(tmp, cache[j]+1);
		}
		cache[i] = tmp;
	}
	return cache;
}

int *Lds(int *arr, int n){
	int *cache = new int[n];
	for(int i=0; i<n; i++)
		cache[i] = 1;
	for(int i=1; i<n; i++){
		int tmp = cache[i];
		for(int j=0; j<i; j++){
			if(arr[j] > arr[i])
				tmp = max(tmp, cache[j]+1);
		}
		cache[i] = tmp;
	}
	return cache;
}

int lbs(int *arr, int n){
	int *lis = Lis(arr, n);
	int *lds = Lds(arr, n);
	int M = 0;
	for(int i=0; i<n; i++){
		M = max(M, lis[i] + lds[i]);
	}
	return M-1;
}

int main(){
	int arr[] = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};
  	int n = sizeof(arr)/sizeof(arr[0]);
  	printf("Length of LBS is %d\n", lbs( arr, n ) );
	return 0;
}

