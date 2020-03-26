// http://www.geeksforgeeks.org/largest-sum-contiguous-subarray/

#include <bits/stdc++.h>
using namespace std;

int maxSubArraySum(int *a, int n){
	int Max = a[0];
	int max_here = 0;
	for(int i=0; i<n; i++){
		max_here += a[i];
		if(max_here < 0)
			max_here = 0;
		if(Max < max_here)
			Max = max_here;
	}
	// Take care of case if all are negative
	return Max;
}

int DP(int *a, int n){
	int cache[n];
	for(int i=0; i<n; i++)
		cache[i] = a[i];
	for(int i=1; i<n; i++){
		if(cache[i-1] + a[i] > a[i])
			cache[i] = cache[i-1] + a[i];
	}
	int m = cache[0];
	for(int i=1; i<n; i++)
		m = max(m, cache[i]);
	return m;
}

int main() {
	int a[] =  {-2, 3, 4, -1, -2, -1, 5, 3};
   	int n = sizeof(a)/sizeof(a[0]);
   	int max_sum = maxSubArraySum(a, n);
   	printf("Maximum contiguous sum is %d\n", max_sum);
   	cout<<DP(a, n);
	return 0;
}

