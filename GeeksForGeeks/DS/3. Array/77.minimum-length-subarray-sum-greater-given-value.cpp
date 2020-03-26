// http://www.geeksforgeeks.org/minimum-length-subarray-sum-greater-given-value/

#include <iostream>
#include "array.h"

int smallestSubWithSum(int *a, int n, int x){
	int sum = 0;
	int sumArr[n];
	for(int i=0; i<n; i++){
		sum += a[i];
		sumArr[i] = sum;
	}
	int i=0;
	int j=0;
	sum = 0;
	int res = INT_MAX;
	while(i<n){
		if(sumArr[i] < x)
			i++;
		else {
			while(sumArr[i] - sumArr[j] > x)
				j++;
			res = min(res, i-j+1);
			i++;
		}
	}
	return res;
}

int main(){
	int arr1[] = {1, 4, 45, 6, 10, 19};
    int x = 51;
    int n1 = sizeof(arr1)/sizeof(arr1[0]);
    cout<<smallestSubWithSum(arr1, n1, x) << endl;
 
    int arr2[] = {1, 10, 5, 2, 7};
    int n2 = sizeof(arr2)/sizeof(arr2[0]);
    x  = 9;
    cout << smallestSubWithSum(arr2, n2, x) << endl;
 
    int arr3[] = {1, 11, 100, 1, 0, 200, 3, 2, 1, 250};
    int n3 = sizeof(arr3)/sizeof(arr3[0]);
    x  = 280;
    cout << smallestSubWithSum(arr3, n3, x) << endl;
	return 0;
}

