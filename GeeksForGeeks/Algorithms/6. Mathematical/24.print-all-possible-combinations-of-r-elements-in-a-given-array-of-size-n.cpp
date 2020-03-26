// http://www.geeksforgeeks.org/print-all-possible-combinations-of-r-elements-in-a-given-array-of-size-n

#include <iostream>
#include <cstdio>
using namespace std;

void printArray(int *a, int n){
	for(int i=0; i<n; i++)
		cout<<a[i]<<" ";
	cout<<'\n';
}

void printCombinationUtil(int *arr, int *data, int n, int r, int levelR){
	if(levelR == r){
		printArray(data, r);
		return;
	}
	if(n == r-levelR){
		for(int i=levelR; i<r; i++)
			data[i] = arr[i-levelR];
		printArray(data, r);
		return;
	}
	printCombinationUtil(arr+1, data, n-1, r, levelR);
	data[levelR] = arr[0];
	levelR++;
	printCombinationUtil(arr+1, data, n-1, r, levelR);
}

void printCombination(int *arr, int n, int r){
	int *data = new int[r];
	printCombinationUtil(arr, data, n, r, 0);
}

int main(){
	int arr[] = {1, 2, 3, 4, 5};
    int r = 3;
    int n = sizeof(arr)/sizeof(arr[0]);
    printCombination(arr, n, r);
	return 0;
}

