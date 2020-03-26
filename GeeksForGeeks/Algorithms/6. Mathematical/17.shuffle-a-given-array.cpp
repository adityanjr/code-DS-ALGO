// http://www.geeksforgeeks.org/shuffle-a-given-array/

#include <iostream>
#include <cstdio>
#include <time.h>
using namespace std;

void swap(int &a, int &b){
	int tmp = a;
	a = b;
	b = tmp;
}

void printArray(int *arr, int n){
	for(int i=0; i<n; i++)
		cout<<arr[i]<<" ";
}

void randomize(int *arr, int n){
	srand(time(NULL));
	for(int i=n-1; i>=0; i--){
		int idx = rand()%(i+1);
		swap(arr[idx], arr[i]);
	}
}

int main(){
	int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int n = sizeof(arr)/ sizeof(arr[0]);
    randomize (arr, n);
    printArray(arr, n);
	return 0;
}

