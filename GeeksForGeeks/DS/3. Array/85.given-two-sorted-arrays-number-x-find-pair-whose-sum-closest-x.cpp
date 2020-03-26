// http://www.geeksforgeeks.org/given-two-sorted-arrays-number-x-find-pair-whose-sum-closest-x

#include <iostream>
#include <climits>
#include <cmath>
#include "array.h"

int printClosest(int *a, int *b, int n, int m, int x){
	int i=n-1, j = 0;
	int least = INT_MAX;
	while(i>=0 && j<m){
		int sum = a[i]+b[j];
		least = min(least, abs(x-sum));
		if(least == 0)
			return 0;
		else if(sum > x){
			i--;
		}
		else{
			j++;
		}
	}
	return least;
}

int main(){
	int ar1[] = {1, 4, 5, 7};
    int ar2[] = {10, 20, 30, 40};
    int m = sizeof(ar1)/sizeof(ar1[0]);
    int n = sizeof(ar2)/sizeof(ar2[0]);
    int x = 32;
    cout<<printClosest(ar1, ar2, m, n, x);
	return 0;
}

