// http://www.geeksforgeeks.org/sort-array-wave-form-2/

#include <iostream>
#include <climits>
#include <cstdio>
#include <algorithm>
using namespace std;

void printArr(int arr[], int n) {
	for (int i = 0; i < n; ++i)
		cout<<arr[i]<<" ";
	cout<<'\n';
}

void swap(int &a, int &b) {
	int tmp = a;
	a = b;
	b = tmp;
}

void sortWaveForm(int *arr, int n){
	sort(arr, arr+n);
	for (int i = 0; i < n-1; i+=2) {
			swap(arr[i], arr[i+1]);
		}	
}

int main(){
	int arr[] = {10, 5, 6, 3, 2, 20, 100, 80};
	sortWaveForm(arr, sizeof(arr)/sizeof(*arr));
	printArr(arr, sizeof(arr)/sizeof(*arr));
	return 0;
}