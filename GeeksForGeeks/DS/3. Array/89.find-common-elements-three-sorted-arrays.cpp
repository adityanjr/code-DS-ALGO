// http://www.geeksforgeeks.org/find-common-elements-three-sorted-arrays/

#include <iostream>
#include "array.h"

void findCommon(int *a, int *b, int *c, int n, int m, int l){
	int i=0, j=0, k=0;
	while(i<n && j<m && k<l){
		if(a[i] == b[j]){
			if(c[k] == a[i]){
				cout<<a[i]<<" ";
				i++; j++; k++;
			}
			else if(a[i] < c[k]){
				i++;
				j++;
			}
			else
				k++;
		}
		else if(a[i] < b[j])
			i++;
		else
			j++;
	}
}

int main(){
	int ar1[] = {1, 5, 5};
    int ar2[] = {3, 4, 5, 5, 20};
    int ar3[] = {5, 5, 10, 20};
    int n1 = sizeof(ar1)/sizeof(ar1[0]);
    int n2 = sizeof(ar2)/sizeof(ar2[0]);
    int n3 = sizeof(ar3)/sizeof(ar3[0]);
 
    cout << "Common Elements are ";
    findCommon(ar1, ar2, ar3, n1, n2, n3);
	return 0;
}

