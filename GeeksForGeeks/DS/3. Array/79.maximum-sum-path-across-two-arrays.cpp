// http://www.geeksforgeeks.org/maximum-sum-path-across-two-arrays

#include <iostream>
#include "array.h"

int maxPathSum(int *a, int *b, int n, int m){
	int sum1 = 0, sum2 = 0;
	int i=0, j=0;
	int res=0;
	while(i<n && j<m){
		if(a[i] == b[j]){
			res += max(sum1, sum2);
			res += a[i];
			sum1 = 0;
			sum2 = 0;
			i++;
			j++;
		}
		else if(a[i] < a[j]){
			sum1 += a[i];
			i++;
		}
		else {
			sum2 += b[j];
			j++;
		}
	}
	if(j == m){
		while(i<n){
			sum1 += a[i];
			i++;
		}
	}
	else{
		while(j<m){
			sum2 += b[j];
			j++;
		}
	}
	res += max(sum1, sum2);
	return res;
}

int main(){
	int ar1[]  = {2, 3, 7, 10, 12, 15, 30, 34};
    int ar2[] =  {1, 5, 7, 8, 10, 15, 16, 19};
    int m = sizeof(ar1)/sizeof(ar1[0]);
    int n = sizeof(ar2)/sizeof(ar2[0]);
    cout << maxPathSum(ar1, ar2, m, n);
	return 0;
}

