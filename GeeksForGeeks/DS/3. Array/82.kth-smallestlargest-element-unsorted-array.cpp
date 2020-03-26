// http://www.geeksforgeeks.org/kth-smallestlargest-element-unsorted-array

#include <iostream>
#include <algorithm>
#include <vector>
#include "array.h"

int kthSmallest(int *a, int n, int k){
	vector<int> v;
	for(int i=0; i<k; i++)
		v.push_back(a[i]);

	make_heap(v.begin(), v.end());
	for(int i=k; i<n; i++){
		if(v[0] > a[i]){
			pop_heap(v.begin(), v.end());
			v.pop_back();
			v.push_back(a[i]);
			push_heap(v.begin(), v.end());
		}
	}
	return v[0];
}

int main(){
	int arr[] = {12, 3, 5, 7, 4, 19};
    int n = sizeof(arr)/sizeof(arr[0]), k = 2;
    cout <<k<<"'th smallest element is " <<  kthSmallest(arr, n, k);
	return 0;
}

