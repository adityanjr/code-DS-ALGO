// http://www.geeksforgeeks.org/kth-smallestlargest-element-unsorted-array-set-2-expected-linear-time/

#include <iostream>
#include <cstdlib>
#include "array.h"

int partition(int *a, int start, int end){
	if(start > end)
		return -1;
	if(start == end)
		return start;
	int n = end-start +1;
	int idx = start + rand()%n;
	swap(&a[idx], &a[end]);
	int piv = a[end];
	int j=start-1;
	for(int i=start; i<=end; i++){
		if(a[i] < piv){
			j++;
			swap(&a[i], &a[j]);
		}
	}
	j++;
	swap(&a[j], &a[end]);
	return j;
}

int kthSmallest(int *a, int start, int end, int k){
	while(start <= end && start < k){
		int idx = partition(a, start, end);
		if(idx+1 == k){
			return a[idx];
		}
		else if(idx+1 > k)
			end = idx-1;
		else
			start = idx + 1;
	}
}

int main(){
	int arr[] = {12, 3, 5, 7, 4, 19, 26};
    int n = sizeof(arr)/sizeof(arr[0]), k = 5;
    cout << "K'th smallest element is " << kthSmallest(arr, 0, n-1, k);
	return 0;
}

