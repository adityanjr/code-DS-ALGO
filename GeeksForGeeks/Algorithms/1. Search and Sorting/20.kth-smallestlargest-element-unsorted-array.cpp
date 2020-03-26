// http://www.geeksforgeeks.org/kth-smallestlargest-element-unsorted-array/

#include <iostream>
#include <climits>
#include <cstdio>
using namespace std;

void swap(int &a, int &b) {
	int tmp = a;
	a = b;
	b = tmp;
}

int partition(int *arr, int start, int end) {
	int x = arr[end];
	int j = start;
	for (int i = start; i < end; ++i) {
		if(arr[i] <= x) {
			swap(arr[j], arr[i]);
			j++;
		}
	}
	swap(arr[j], arr[end]);
	return j;
}

int quickSelection(int *arr, int start, int end, int k){
	if(k>0 && k <= end-start+1) {
		int ind = partition(arr, start, end);
		if(ind-start+1 == k)
			return arr[ind];
		else if(ind-start+1 < k)
			return quickSelection(arr, ind+1, end, k-(ind+1-start));
		else
			return quickSelection(arr, start, ind-1, k);
	}
	return -1;
}

int main(){
	int arr[] = {12, 3, 5, 7, 4, 19, 26};
    int n = sizeof(arr)/sizeof(arr[0]), k = 2;
    cout << "K'th smallest element is " << quickSelection(arr, 0, n-1, k);
	return 0;
}