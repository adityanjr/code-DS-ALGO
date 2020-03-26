// http://www.geeksforgeeks.org/two-elements-whose-sum-is-closest-to-zero

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int minAbsSumPair(int *a, int n){
	sort(a, a+n);
	int k = 0;
	int start = 0, end = n-1;
	int diff = INT_MAX;
	while(start < end){
		int sum = a[start] + a[end];
		if(abs(sum) < diff)
			diff = abs(sum);
		if(sum == k)
			return k;
		if(sum > k)
			end--;
		else
			start++;
	}
	return diff;
}

int main() {
  int arr[] = {1, 60, -10, 70, -80};
  int n = sizeof(arr)/sizeof(arr[0]);
  cout<<minAbsSumPair(arr, n);
  getchar();
  return 0;
}
