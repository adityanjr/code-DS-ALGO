// http://www.geeksforgeeks.org/find-number-of-triangles-possible/

#include <iostream>
#include <algorithm>
#include "array.h"

int findNumberOfTriangles(int *a, int n){
	sort(a, a+n);
	int count = 0;
	for(int i=n-1; i>=0; i--){
		int j = i-1, k= i-2;
		while(k>=0 && j>k){
			if(a[k]+a[j]>a[i]){
				cout<<a[k]<<" "<<a[j]<<" "<<a[i]<<'\n';
				k--;
				count++;
			}
			else {
				j--;
				k = j-1;
			}
			if(k<0){
				j--;
				k = j-1;
			}
			
		}
	}
	return count;
}

int main(){
	int arr[] =   {4, 6, 3, 7};
    int size = sizeof( arr ) / sizeof( arr[0] );
 
    printf("Total number of triangles possible is %d ", findNumberOfTriangles( arr, size ));
	return 0;
}

