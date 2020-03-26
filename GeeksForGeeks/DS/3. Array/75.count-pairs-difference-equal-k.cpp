// http://www.geeksforgeeks.org/count-pairs-difference-equal-k

#include <iostream>
#include <algorithm>
#include "array.h"

int countPairsWithDiffK(int *a, int n, int k){
	sort(a, a+n);
	int l=0, r=0;
	int diff=0;
	int count = 0;
	while(l < n && r<n){
		diff = a[r]-a[l];
		if(diff == k){
			count++;
			l++;
			r++;
		}
		else if(diff < k)
			r++;
		else
			l++;
	}
	return count;
}

int main(){
	int arr[] =  {1, 5, 3, 4, 2};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 3;
    cout << "Count of pairs with given diff is "<< countPairsWithDiffK(arr, n, k);
	return 0;
}

