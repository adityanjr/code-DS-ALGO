// http://www.geeksforgeeks.org/find-the-minimum-distance-between-two-numbers/

#include <iostream>
#include <cmath>
#include <climits>
#include "array.h"

int minDist(int *a, int n, int x, int y){
	int k=-1, l=-1;
	int min = INT_MAX;
	for(int i=0; i<n; i++){
		if(a[i] == x){
			k = i;
		}
		else if(a[i] == y)
			l = i;
		if(k>=0 && l >=0 && min > abs(k-l))
			min = abs(k-l);
	}
	return min;
}

int main(){
    int arr[] ={3, 5, 6, 4, 2, 6, 3, 0, 0, 5, 4, 6, 8, 3};
    int n = sizeof(arr)/sizeof(arr[0]);
    int x = 3;
    int y = 6;
 
    printf("Minimum distance between %d and %d is %d\n", x, y,
              minDist(arr, n, x, y));
    return 0;
}
