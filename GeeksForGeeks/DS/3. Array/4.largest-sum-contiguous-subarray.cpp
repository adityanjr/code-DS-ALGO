// http://www.geeksforgeeks.org/largest-sum-contiguous-subarray/

#include <iostream>
using namespace std;

int maxSubArraySum(int *a, int n){
	int max = a[0];
	int max_here = 0;
	for(int i=0; i<n-1; i++){
		max_here += a[i];
		if(max_here > max)
		    max = max_here;
		if(max_here < 0)
		    max_here = 0;
	}
	max_here += a[n-1];
	if(max_here > max)
		max = max_here;
	return max;
}

int main(){
	int a[] =  {-2, -3, -4, -1, -2, -1, -5, -5};
	int n = sizeof(a)/sizeof(a[0]);
   	int max_sum = maxSubArraySum(a, n);
   	printf("Maximum contiguous sum is %d\n", max_sum);
   	return 0;
}
