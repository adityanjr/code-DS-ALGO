// http://www.geeksforgeeks.org/median-of-two-sorted-arrays-of-different-sizes
/*********/

#include<iostream>
#include "array.h"

float MO2(int a, int b){
	return (a+b)/2.0;
}

float MO3(int a, int b, int c){
	return a+b+c-min(a, min(b, c))-max(a, max(b, c));	
}

float MO4(int a, int b, int c, int d){
	int ma = max(max(a, b), max(c, d));
	int mi = min(min(a, b), min(c, d));
	return (a+b+c+d-ma-mi)/2.0;
}

float findMedianUtil(int *a, int n, int *b, int m){
	// n<m;
	if(n==1){
		if(m==1)
			return MO2(a[0], b[0]);
		if(m & 1){
			return MO4(a[0], b[(m/2)-1], b[(m/2)], b[(m/2)+1]);
		}
		else {
			return MO3(a[0], b[m/2], b[(m/2)-1]);
		}
	}
	else if(n==2){
		if(m==2){
			return MO4(a[0], a[1], b[0], b[1]);
		}
		else if(m & 1){
			return MO3(b[m/2], max(a[0], b[(m/2)-1]), max(a[1], b[(m/2)-1]));
		}
		else {
			return MO4(a[0], a[1], b[(m/2)-1], b[(m/2)]);
		}
	}
	int idxa = (n-1)/2;
	int idxb = (m-1)/2;
	if(a[idxa] <= b[idxb]){
		return findMedianUtil(a+idxa, (n/2)+1, b, m-idxa);
	}
	else {
		return findMedianUtil(a, (n/2)+1, b+idxa, m-idxa);
	}
}

float findMedian(int *a, int n, int *b, int m){
	if(n>m)
		return findMedianUtil(b, m, a, n);
	return findMedianUtil(a, n, b, m);
}

int main(){
	int A[] = {900};
    int B[] = {11, 23, 30, 45};
 
    int N = sizeof(A) / sizeof(A[0]);
    int M = sizeof(B) / sizeof(B[0]);
 
    printf( "%f", findMedian( A, N, B, M ) );
    return 0;
	return 0;
}

