// http://www.geeksforgeeks.org/check-if-array-elements-are-consecutive/

#include <iostream>
#include "array.h"

bool areConsecutive(int *a, int n){
	int x = 0;
	int min = a[0], max = a[0];
	for(int i=0; i<n; i++){
		x = x^a[i];
		if(min > a[i])
			min = a[i];
		if(max < a[i])
			max = a[i];
	}
	if(max-min+1 != n)
		return false;
	for(int i=min; i<=max; i++){
		x = x^i;
	}
	cout<<x;
	if(x==0)
		return true;
	return false;
}

int main(){
    int arr[]= {5, 4, 2, 3, 1, 6};
    int n = sizeof(arr)/sizeof(arr[0]);
    if(areConsecutive(arr, n) == true)
        printf(" Array elements are consecutive ");
    else
        printf(" Array elements are not consecutive ");
    getchar();
    return 0;
}
