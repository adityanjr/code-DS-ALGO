// http://www.geeksforgeeks.org/dynamic-programming-subset-sum-problem

#include <bits/stdc++.h>
using namespace std;

bool isSubsetSum(int *set, int n, int sum){
	bool cache[sum+1][n+1];
	for(int i=0; i<=n; i++)
		cache[0][i] = 1;
	for(int i=1; i<=sum; i++)
		cache[i][0] = 0;
	for(int i=1; i<=sum; i++){
		for(int j=1; j<=n; j++){
			if(set[j-1] > i)
				cache[i][j] = cache[i][j-1];
			else
				cache[i][j] = cache[i][j-1] || cache[i-set[j-1]][j-1];
		}
	}
	return cache[sum][n];
}

int main(){
	int set[] = {3, 34, 4, 12, 5, 2};
	int sum = 9;
  	int n = sizeof(set)/sizeof(set[0]);
  	if (isSubsetSum(set, n, sum) == true)
    	printf("Found a subset with given sum");
  	else
     	printf("No subset with given sum");
	return 0;
}

