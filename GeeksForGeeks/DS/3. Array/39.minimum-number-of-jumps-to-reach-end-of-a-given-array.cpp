// http://www.geeksforgeeks.org/minimum-number-of-jumps-to-reach-end-of-a-given-array
/************/

#include <iostream>
#include <cstring>
#include <climits>
#include "array.h"

int minJumps(int *a, int n){
	int helper[n];
	memset(helper, 0, sizeof(helper));
	helper[n-1] = 0;
	for(int i=n-2; i>=0; i--){
		if(a[i] == 0)
			helper[i] = INT_MAX;
		else if(a[i] >= n-1-i){
			helper[i]++;
		}
		else{
			int min = INT_MAX;
			for(int j=i+1; j < n && j <= a[i]+i; j++){
				if(min > helper[j])
					min = helper[j];
			}
			if(min != INT_MAX){
				helper[i] = min+1;
			}
			else
				helper[i] = min;
		}
	}
	return helper[0];
}

int main(){
    int arr[] = {1, 3, 6, 1, 0, 9};
    int size = sizeof(arr)/sizeof(int);
    printf("Minimum number of jumps to reach end is %d ", minJumps(arr,size));
    return 0;
}
