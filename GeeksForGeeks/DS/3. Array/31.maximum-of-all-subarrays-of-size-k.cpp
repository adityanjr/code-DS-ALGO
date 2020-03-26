// http://www.geeksforgeeks.org/maximum-of-all-subarrays-of-size-k/

#include <iostream>
#include <deque>
#include "array.h"

void printKMax(int *a, int n, int k){
	deque<int> Q(k);
	int i;
	for(i=0; i<k; i++){
		while(!Q.empty() && a[Q.back()] <= a[i]){
			Q.pop_back();
		}
		Q.push_back(i);
	}
	
	for(; i<n; i++){
		cout<<a[Q.front()]<<" ";
		while(!Q.empty() && Q.front() <= i-k){
			Q.pop_front();
		}
		while(!Q.empty() && a[Q.back()] < a[i])
			Q.pop_back(); 
		Q.push_back(i);
	}
	cout << a[Q.front()];
}

int main(){
    int arr[] = {12, 1, 78, 90, 57, 89, 56};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 3;
    printKMax(arr, n, k);
    return 0;
}
