// http://www.geeksforgeeks.org/find-smallest-value-represented-sum-subset-given-array/
/**/

#include <iostream>
#include "array.h"

int findSmallest(int *a, int n){
	int res = 1;
	for(int i=0; i<n && a[i] <= res; i++){
		res += a[i];
	}
	return res;
}

int main(){
	int arr1[] = {1, 3, 4, 5};
   int n1 = sizeof(arr1)/sizeof(arr1[0]);
   cout << findSmallest(arr1, n1) << endl;
 
   int arr2[] = {1, 2, 6, 10, 11, 15};
   int n2 = sizeof(arr2)/sizeof(arr2[0]);
   cout << findSmallest(arr2, n2) << endl;
 
   int arr3[] = {1, 1, 1, 1};
   int n3 = sizeof(arr3)/sizeof(arr3[0]);
   cout << findSmallest(arr3, n3) << endl;
 
   int arr4[] = {1, 1, 3, 4};
   int n4 = sizeof(arr4)/sizeof(arr4[0]);
   cout << findSmallest(arr4, n4) << endl;
	return 0;
}

