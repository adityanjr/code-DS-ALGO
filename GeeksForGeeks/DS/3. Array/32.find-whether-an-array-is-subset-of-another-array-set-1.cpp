// http://www.geeksforgeeks.org/find-whether-an-array-is-subset-of-another-array-set-1/

#include <iostream>
#include <map>
#include "array.h"

bool isSubset(int *a1, int *a2, int m, int n){
	map<int, int> M;
	for(int i=0; i<n; i++){
		if(M.count(a2[i]) == 0){
			M[a2[i]] = 1;
		}
		else {
			M[a2[i]]++;
		}
	}
	int count = 0;
	for(int i=0; i<m; i++){
		if(M.count(a1[i]) > 0){
			M[a1[i]]--;
			count++;
		}
		if(count == n)
			return true;
	}
	return false;
}

int main(){
    int arr1[] = {11, 1, 13, 21, 3, 7};
    int arr2[] = {11, 3, 7, 1};
   
    int m = sizeof(arr1)/sizeof(arr1[0]);
    int n = sizeof(arr2)/sizeof(arr2[0]);
 
    if(isSubset(arr1, arr2, m, n))
      printf("arr2[] is subset of arr1[] ");
    else
      printf("arr2[] is not a subset of arr1[] ");      
 
    getchar();
    return 0;
}
