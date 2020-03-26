// http://www.geeksforgeeks.org/shuffle-a-given-array/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "array.h"

void randomize(int *a, int n){
	srand (time(NULL) );
	for(int i=n-1; i>=0; i--){
		int idx = rand()%(i+1);
		swap(&a[idx], &a[i]);
	}
}

int main(){
	int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int n = sizeof(arr)/ sizeof(arr[0]);
    randomize (arr, n);
    printArray(arr, n);
	return 0;
}

