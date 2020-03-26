// http://www.geeksforgeeks.org/sort-array-according-order-defined-another-array

#include <iostream>
#include <map>
#include "array.h"

void sortAccording(int *a, int *b, int n, int m){
	map<int, int> M;
	for(int i=0; i<m; i++){
		M[b[i]] = 1;
	}
	int j=n-1;
	for(int i=n-1; i>=0; i--){
		if(M.count(a[i]) == 0){
			swap(&a[i], &a[j]);
			j--;
		}
		else
			M[a[i]] = M[a[i]]+1;
	}
	j=0;
	for(int i=0; i < m; i++){
		int tmp = M[b[i]]-1;
		while(tmp>0){
			a[j] = b[i];
			j++;
			tmp--;
		}
	}
}

int main(){
	int A1[] = {2, 1, 2, 5, 7, 1, 9, 3, 6, 8, 8};
    int A2[] = {2, 1, 8, 3};
    int m = sizeof(A1)/sizeof(A1[0]);
    int n = sizeof(A2)/sizeof(A2[0]);
    cout << "Sorted array is \n";
    sortAccording(A1, A2, m, n);
    printArray(A1, m);
	return 0;
}

