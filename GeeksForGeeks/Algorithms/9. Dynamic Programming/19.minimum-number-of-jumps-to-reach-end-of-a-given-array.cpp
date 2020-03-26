// http://www.geeksforgeeks.org/minimum-number-of-jumps-to-reach-end-of-a-given-array

#include <iostream>
#include <cstdio>
using namespace std;

#define INF 99

int minJumps(int *arr, int n){
	int cache[n];
	for(int i=0; i<n; i++)
		cache[i] = INF;
	cache[n-1] = 0;
	for(int i=n-2; i>=0; i--){
		if(arr[i] != 0){
			int step = arr[i];
			int Min = INF;
			for(int j=i+1; j<n && j-i <= step; j++){
				Min = min(Min, cache[j]);
			}
			if(Min != INF)
				cache[i] = Min+1;
		}
	}
	return cache[0];
}

int main(){
	int arr[] = {1, 3, 6, 3, 2, 3, 6, 8, 9, 5};
    int size = sizeof(arr)/sizeof(int);
    printf("Minimum number of jumps to reach end is %d ", minJumps(arr,size));
	return 0;
}

