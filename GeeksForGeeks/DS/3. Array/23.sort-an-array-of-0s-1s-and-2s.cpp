// http://www.geeksforgeeks.org/sort-an-array-of-0s-1s-and-2s/
//************

#include <iostream>
#include "array.h"

void sort012(int *a, int n){
	int j=0, k=n-1, i=0;
	while(i<n && i<=k) {
		if(a[i]==0 && i==j){
			j++;
			i++;
		}
		else if(a[i]==0){
			swap(&a[i], &a[j]);
			j++;
		}
		else if(a[i]==2){
			swap(&a[i], &a[k]);
			k--;
		}
		else {
			i++;
		}
	}
}

int main(){
    int arr[] = {0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1};
    int arr_size = sizeof(arr)/sizeof(arr[0]);
    int i;
 
    sort012(arr, arr_size);
    printf("array after segregation ");
    printArray(arr, arr_size);
    return 0;
}
