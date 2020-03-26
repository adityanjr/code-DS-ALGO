// http://www.geeksforgeeks.org/longest-monotonically-increasing-subsequence-size-n-log-n/
/***/

#include <bits/stdc++.h>
using namespace std;

int findCeil(int *cache, int start, int end, int x){
	if(start > end)
		return -1;
	if(start == end)
		return start;
	int mid = (start+end)/2;
	if(cache[mid] == x)
		return mid;
	if(cache[mid] > x)
		return findCeil(cache, start, mid, x);
	else {
		return findCeil(cache, mid+1, end, x);
	}
}

int LIS(int *A, int n){
	int cache[n];
	int len = 1;
	cache[0] = A[0];
	for(int i=1; i<n; i++){
		if(cache[0] > A[i])
			cache[0] = A[i];
		else if(A[i] > cache[len-1])
			cache[len++] = A[i];
		else
			cache[findCeil(cache, 0, i-1, A[i])] = A[i];
	}
	return len;
}

int main(){
	int A[] = { 5, 3, 2 ,4, 7, 8, 1, 3, 6 };
    int n = sizeof(A)/sizeof(int);

    printf("Length of Longest Increasing Subsequence is %d\n",
            LIS(A, n));

	return 0;
}
