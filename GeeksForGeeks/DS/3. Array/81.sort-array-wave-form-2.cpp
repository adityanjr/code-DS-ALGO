// http://www.geeksforgeeks.org/sort-array-wave-form-2
/***/

#include <iostream>
#include "array.h"

void sortInWave(int *a, int n){
	if(n == 1)
		return;
	if(a[0] < a[1])
		swap(&a[0], &a[1]);
	for(int i=2; i<n; i+=2){
		if(a[i-1] > a[i])
			swap(&a[i-1], &a[i]);
		if(a[i+1] > a[i])
			swap(&a[i], &a[i+1]);
	}
}

int main(){
	int arr[] = {20, 10, 8, 6, 4, 2};
    int n = sizeof(arr)/sizeof(arr[0]);
    sortInWave(arr, n);
    cout << "Sorted array \n";
    for (int i=0; i<n; i++)
       cout << arr[i] << " ";
	return 0;
}

