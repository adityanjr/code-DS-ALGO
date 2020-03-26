// http://www.geeksforgeeks.org/segregate-0s-and-1s-in-an-array-by-traversing-array-once/

#include <iostream>
#include "array.h"

void segregate0and1(int *a, int n){
	int j=0;
	for(int i=0; i<n; i++){
		if(a[i] == 0){
			swap(&a[i], &a[j]);
			j++;
		}
	}
}

int main(){
    int arr[] = {0, 1, 0, 1, 1, 1};
    int i, arr_size = sizeof(arr)/sizeof(arr[0]);
 
    segregate0and1(arr, arr_size);
 
    printf("array after segregation ");
    for (i = 0; i < 6; i++)
        printf("%d ", arr[i]);
 
    return 0;
}
