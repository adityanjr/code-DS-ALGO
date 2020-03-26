// http://www.geeksforgeeks.org/move-zeroes-end-array/

#include <iostream>
#include "array.h"

void pushZerosToEnd(int *a, int n){
	int j=-1;
	for(int i=0; i<n; i++){
		if(a[i] != 0){
			j++;
			swap(&a[j], &a[i]);
		}
	}
}

int main(){
	int arr[] = {1, 9, 8, 4, 0, 0, 2, 7, 0, 6, 0, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    pushZerosToEnd(arr, n);
    cout << "Array after pushing all zeros to end of array :\n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
	return 0;
}

